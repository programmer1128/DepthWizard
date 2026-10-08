if(EXISTS "/home/aritra/Desktop/DepthWizard/drogon_service/gis_service/build-integration/test/raster_ingest_service_test")
  if(NOT EXISTS "/home/aritra/Desktop/DepthWizard/drogon_service/gis_service/build-integration/test/raster_ingest_service_test[1]_tests.cmake" OR
     NOT "/home/aritra/Desktop/DepthWizard/drogon_service/gis_service/build-integration/test/raster_ingest_service_test[1]_tests.cmake" IS_NEWER_THAN "/home/aritra/Desktop/DepthWizard/drogon_service/gis_service/build-integration/test/raster_ingest_service_test" OR
     NOT "/home/aritra/Desktop/DepthWizard/drogon_service/gis_service/build-integration/test/raster_ingest_service_test[1]_tests.cmake" IS_NEWER_THAN "${CMAKE_CURRENT_LIST_FILE}")
    include("/usr/share/cmake/Modules/GoogleTestAddTests.cmake")
    gtest_discover_tests_impl(
      TEST_EXECUTABLE [==[/home/aritra/Desktop/DepthWizard/drogon_service/gis_service/build-integration/test/raster_ingest_service_test]==]
      TEST_EXECUTOR [==[]==]
      TEST_WORKING_DIR [==[/home/aritra/Desktop/DepthWizard/drogon_service/gis_service/build-integration/test]==]
      TEST_EXTRA_ARGS [==[]==]
      TEST_PROPERTIES [==[]==]
      TEST_PREFIX [==[]==]
      TEST_SUFFIX [==[]==]
      TEST_FILTER [==[]==]
      NO_PRETTY_TYPES [==[FALSE]==]
      NO_PRETTY_VALUES [==[FALSE]==]
      TEST_LIST [==[raster_ingest_service_test_TESTS]==]
      CTEST_FILE [==[/home/aritra/Desktop/DepthWizard/drogon_service/gis_service/build-integration/test/raster_ingest_service_test[1]_tests.cmake]==]
      TEST_DISCOVERY_TIMEOUT [==[5]==]
      TEST_DISCOVERY_EXTRA_ARGS [==[]==]
      TEST_XML_OUTPUT_DIR [==[]==]
    )
  endif()
  include("/home/aritra/Desktop/DepthWizard/drogon_service/gis_service/build-integration/test/raster_ingest_service_test[1]_tests.cmake")
else()
  add_test(raster_ingest_service_test_NOT_BUILT raster_ingest_service_test_NOT_BUILT)
endif()
