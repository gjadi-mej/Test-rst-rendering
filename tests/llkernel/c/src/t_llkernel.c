/*
 * C
 *
 * Copyright 2023 MicroEJ Corp. All rights reserved.
 * Use of this source code is governed by a BSD-style license that can be found with this software.
 */

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <limits.h>

#include "t_llkernel.h"
#include "../../../../framework/c/embunit/embUnit/embUnit.h"
#include "../../../../framework/c/utils/inc/u_print.h"


// --------------------------------------------------------------------------------
// -                                  Constants                                   -
// --------------------------------------------------------------------------------

/**
 * Returned value when function call has succeeded.
 */
#define LLKERNEL_OK (0)

/**
 * Returned value when function call has failed.
 */
#define LLKERNEL_ERROR (-1)

#define COUNTOF(__BUFFER__)        (sizeof(__BUFFER__) / sizeof(*(__BUFFER__)))

#define NUMBER_OF_FEATURES  6
#define FLASH_PAGE_SIZE                   0x100     /* 65536 pages of 256 bytes */


extern int32_t LLKERNEL_IMPL_allocateFeature__II(int32_t size_ROM, int32_t size_RAM);
extern int32_t LLKERNEL_IMPL_getFeatureAddressROM__I(int32_t handle);
extern int32_t LLKERNEL_IMPL_getFeatureAddressRAM__I(int32_t handle);
extern int32_t LLKERNEL_IMPL_copyToROM__LiceTea_lang_Ram_2LiceTea_lang_Ram_2I(void *dest_address_ROM, void *src_address, int32_t size);
extern int32_t LLKERNEL_IMPL_flushCopyToROM(void);
extern int32_t LLKERNEL_IMPL_getAllocatedFeaturesCount(void);
extern int32_t LLKERNEL_IMPL_getFeatureHandle__I(int32_t index);
extern void LLKERNEL_IMPL_freeFeature__I(int32_t handle);


extern void _java_max_nb_dynamic_features;
static uint32_t kernel_max_nb_dynamic_features = (uint32_t)(& _java_max_nb_dynamic_features);

static int32_t featureHandles[NUMBER_OF_FEATURES] = {0};

static void cleanup_installed_features() {
	// Free installed features
	int32_t nbAllocatedFeatures = LLKERNEL_IMPL_getAllocatedFeaturesCount();
    while(nbAllocatedFeatures > 0){
		int32_t handle = LLKERNEL_IMPL_getFeatureHandle__I(0);
		// Installed feature found, free it
		LLKERNEL_IMPL_freeFeature__I(handle);
		nbAllocatedFeatures = LLKERNEL_IMPL_getAllocatedFeaturesCount();
    }

	// Reset features handle
	for(int32_t i = 0; i < NUMBER_OF_FEATURES; i++) {
		// Deinit associated feature handle
		featureHandles[i] = 0;
	}
}

/** @brief Function call before running test. */
static void T_LLKERNEL_setUp(void)
{
	UTIL_print_string("\nT_LLKERNEL_setUp\n");
	cleanup_installed_features();
}

/** @brief Function call before running test. */
static void T_LLKERNEL_tearDown(void)
{
	UTIL_print_string("T_LLKERNEL_tearDown\n");
	cleanup_installed_features();
}

/** @brief 	Allocate and install 6 features (more than the default 4 features available)
 *  		test should fail after installing 4 features.
 */
static void T_LLKERNEL_CHECK_resource_allocate(void) {
	UTIL_print_string("LLKERNEL resource allocate\n");
        
    uint8_t resourceBuffer[FLASH_PAGE_SIZE] = {0};
    uint8_t testBuffer[FLASH_PAGE_SIZE] = {0};
    uint32_t resourceSize = 0;
    int32_t installed_features = 0;

    for(int32_t i = 0; i < NUMBER_OF_FEATURES; i++) {
        sprintf((char*)resourceBuffer, "********llkernel %d llkernel*******", i);
        resourceSize = COUNTOF(resourceBuffer);

        int32_t nbAllocatedFeatures = LLKERNEL_IMPL_getAllocatedFeaturesCount();
        TEST_ASSERT_EQUAL_INT(i, nbAllocatedFeatures);

        // Allocate new feature
        featureHandles[i] = LLKERNEL_IMPL_allocateFeature__II(resourceSize, resourceSize);
        if(0 == featureHandles[i]){
        	break;// no more space to allocate new feature
        }

        void *romAddr = (void*)LLKERNEL_IMPL_getFeatureAddressROM__I(featureHandles[i]);
        TEST_ASSERT_NOT_NULL(romAddr);

        void *ramAddr = (void*)LLKERNEL_IMPL_getFeatureAddressRAM__I(featureHandles[i]);
        TEST_ASSERT_NOT_NULL(ramAddr);

        // Install feature
        int32_t result = LLKERNEL_IMPL_copyToROM__LiceTea_lang_Ram_2LiceTea_lang_Ram_2I(romAddr, resourceBuffer, resourceSize);
        TEST_ASSERT_MESSAGE(LLKERNEL_OK == result, "LLKERNEL_IMPL_copyToROM() returned an error");

        result = LLKERNEL_IMPL_flushCopyToROM();
        TEST_ASSERT_MESSAGE(LLKERNEL_OK == result, "LLKERNEL_IMPL_flushCopyToROM() returned an error");

        // Check feature installation consitency
        memcpy((void*)testBuffer, romAddr, resourceSize);
        if(0 != memcmp(testBuffer, resourceBuffer, resourceSize)){
        	TEST_ASSERT_MESSAGE(false, "Corrupted feature content");
        }

        installed_features++;
    }

    if(NUMBER_OF_FEATURES < kernel_max_nb_dynamic_features){
    	TEST_ASSERT_EQUAL_INT(NUMBER_OF_FEATURES, installed_features);
    } else {
    	TEST_ASSERT_EQUAL_INT(kernel_max_nb_dynamic_features, installed_features);
    }
}

/** @brief Allocate, install and free #NUMBER_OF_FEATURES features. */
static void T_LLKERNEL_CHECK_resource_allocate_and_free(void)
{
	UTIL_print_string("LLKERNEL resource allocate and free\n");

    uint8_t resourceBuffer[FLASH_PAGE_SIZE] = {0};
    uint32_t resourceSize = 0;

    for(int32_t i = 0; i < NUMBER_OF_FEATURES; i++) {
        sprintf((char*)resourceBuffer, "********llkernel %d llkernel*******", i);
        resourceSize = COUNTOF(resourceBuffer);

        // Allocate new feature
        featureHandles[i] = LLKERNEL_IMPL_allocateFeature__II(resourceSize, resourceSize);
        if (0 == featureHandles[i]) {
            TEST_ASSERT_MESSAGE(false, "LLKERNEL_IMPL_allocateFeature() returned an error");
        }

        int32_t nbAllocatedFeatures = LLKERNEL_IMPL_getAllocatedFeaturesCount();
		TEST_ASSERT_EQUAL_INT(1, nbAllocatedFeatures);

        void *featureRomAddr = (void*)LLKERNEL_IMPL_getFeatureAddressROM__I(featureHandles[i]);
        TEST_ASSERT_NOT_NULL(featureRomAddr);

        void *featureRamAddr = (void*)LLKERNEL_IMPL_getFeatureAddressRAM__I(featureHandles[i]);
        TEST_ASSERT_NOT_NULL(featureRamAddr);

        // Install feature
        int32_t result = LLKERNEL_IMPL_copyToROM__LiceTea_lang_Ram_2LiceTea_lang_Ram_2I(featureRomAddr, resourceBuffer, resourceSize);
        TEST_ASSERT_MESSAGE(LLKERNEL_OK == result, "LLKERNEL_IMPL_copyToROM() returned an error");

        result = LLKERNEL_IMPL_flushCopyToROM();
        TEST_ASSERT_MESSAGE(LLKERNEL_OK == result, "LLKERNEL_IMPL_flushCopyToROM() returned an error");

        // Check feature installation consistency
        if(0 != memcmp(featureRomAddr, resourceBuffer, resourceSize)){
        	TEST_ASSERT_MESSAGE(false, "Corrupted feature content");
        }

        // Free installed feature
        LLKERNEL_IMPL_freeFeature__I(featureHandles[i]);
        featureHandles[i] = 0;
    }
}


/** @brief Attempt to allocate more memory than the kernel feature block size (ROM/RAM). Expected results is a failure. Feature allocation
 * 			also requires the size of the feature header.
 */
static void T_LLKERNEL_CHECK_resource_allocate_overflow(void)
{
	UTIL_print_string("LLKERNEL resource allocate overflow\n");

    int32_t handle = LLKERNEL_IMPL_allocateFeature__II(INT_MAX, 0x0);
    TEST_ASSERT_EQUAL_INT(0, handle);
    
    handle = LLKERNEL_IMPL_allocateFeature__II(0x0, INT_MAX);
    TEST_ASSERT_EQUAL_INT(0, handle);
}

/** @brief Attempt to install a feature larger than the kernel feature block size. */
static void T_LLKERNEL_CHECK_resource_install_overflow(void)
{
	UTIL_print_string("LLKERNEL resource install overflow\n");

    uint8_t resourceBuffer[FLASH_PAGE_SIZE] = {0};
    uint32_t resourceSize = 0;

	sprintf((char*)resourceBuffer, "********llkernel 0 llkernel*******");
	resourceSize = COUNTOF(resourceBuffer);

	featureHandles[0] = LLKERNEL_IMPL_allocateFeature__II(resourceSize, resourceSize);
	if (0 == featureHandles[0]) {
		// Allocate new feature failed (no more space ?)
		TEST_ASSERT_MESSAGE(false, "LLKERNEL_IMPL_allocateFeature() returned an error");
	}

    void *featureRomAddr = (void*)LLKERNEL_IMPL_getFeatureAddressROM__I(featureHandles[0]);
    TEST_ASSERT_NOT_NULL(featureRomAddr);

    int32_t result = LLKERNEL_IMPL_copyToROM__LiceTea_lang_Ram_2LiceTea_lang_Ram_2I(featureRomAddr, resourceBuffer, INT_MAX);
    TEST_ASSERT_EQUAL_INT(LLKERNEL_ERROR, result);

    LLKERNEL_IMPL_freeFeature__I(featureHandles[0]);
    featureHandles[0] = 0;
}

/** @brief Attempt to install a feature out of the defined ROM area:
 *  		- before
 *  		- after
 *  		- spanning over the end of the defined area
 */
static void T_LLKERNEL_CHECK_resource_install_out_of_bounds(void)
{
	UTIL_print_string("LLKERNEL resource install out of bounds\n");

	uint8_t resourceBuffer[FLASH_PAGE_SIZE] = {0};
	uint32_t resourceSize = 256;

	// Prerequisite is to start with no feature already allocated
    int32_t nbAllocatedFeatures = LLKERNEL_IMPL_getAllocatedFeaturesCount();
	TEST_ASSERT_EQUAL_INT(0, nbAllocatedFeatures);

	// Allocate the first feature
	featureHandles[0] = LLKERNEL_IMPL_allocateFeature__II(resourceSize, resourceSize);
	if (0 == featureHandles[0]) {
		// Allocate new feature failed (no more space ?)
		TEST_ASSERT_MESSAGE(false, "LLKERNEL_IMPL_allocateFeature() returned an error");
	}

	// Check that only one feature is now allocated
	nbAllocatedFeatures = LLKERNEL_IMPL_getAllocatedFeaturesCount();
	TEST_ASSERT_EQUAL_INT(1, nbAllocatedFeatures);

	// Get ROM address of the first allocated feature
	void *featureRomAddr = (void*)LLKERNEL_IMPL_getFeatureAddressROM__I(featureHandles[0]);
	TEST_ASSERT_NOT_NULL(featureRomAddr);

    // Try to copy a sequence of bytes outside ROM area (lower bounds)
    int32_t result = LLKERNEL_IMPL_copyToROM__LiceTea_lang_Ram_2LiceTea_lang_Ram_2I((void*)((uint32_t)featureRomAddr - 0x1000), resourceBuffer, FLASH_PAGE_SIZE);
    if(-1 != result){
    	// Failure expected here but call to LLKERNEL_IMPL_copyToROM() function succeed. Try to call LLKERNEL_IMPL_flushCopyToROM() => fail expected.
    	result = LLKERNEL_IMPL_flushCopyToROM();
    	TEST_ASSERT_EQUAL_INT(-1, result);
    }

    // Try to copy a sequence of bytes outside ROM area (upper bounds)
    result = LLKERNEL_IMPL_copyToROM__LiceTea_lang_Ram_2LiceTea_lang_Ram_2I(featureRomAddr, resourceBuffer, INT_MAX);
    if(-1 != result){
    	// Failure expected here but call to LLKERNEL_IMPL_copyToROM() function succeed. Try to call LLKERNEL_IMPL_flushCopyToROM() => fail expected.
    	result = LLKERNEL_IMPL_flushCopyToROM();
    	TEST_ASSERT_EQUAL_INT(-1, result);
    }

}

TestRef T_LLKERNEL_tests(void)
{
	EMB_UNIT_TESTFIXTURES(fixture_llkernel) {
		new_TestFixture("T_LLKERNEL_resource_allocate", T_LLKERNEL_CHECK_resource_allocate),
		new_TestFixture("T_LLKERNEL_resource_allocate_and_free", T_LLKERNEL_CHECK_resource_allocate_and_free),
		new_TestFixture("T_LLKERNEL_resource_allocate_overflow", T_LLKERNEL_CHECK_resource_allocate_overflow),
		new_TestFixture("T_LLKERNEL_resource_install_overflow", T_LLKERNEL_CHECK_resource_install_overflow),
        new_TestFixture("T_LLKERNEL_resource_install_out_of_bounds", T_LLKERNEL_CHECK_resource_install_out_of_bounds),
	};
	EMB_UNIT_TESTCALLER(llkernel_tests, "LLKERNEL tests", T_LLKERNEL_setUp, T_LLKERNEL_tearDown, fixture_llkernel);

	return (TestRef)&llkernel_tests;
}
