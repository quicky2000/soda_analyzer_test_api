#include "test_api_wrapper.h"
#include "test_api_analyzer_description.h"
#include "test_api_analyzer.h"
#include "common_api.h"

#include <cassert>
#include <iostream>

namespace osm_diff_analyzer_test_api
{
  //----------------------------------------------------------------------------
  const char * test_api_wrapper::get_api_version(void)
  {
    return MODULE_LIBRARY_IF_VERSION;
  }

  //----------------------------------------------------------------------------
  uint32_t test_api_wrapper::get_api_size(void)
  {
    return MODULE_LIBRARY_IF_API_SIZE;
  }

  //----------------------------------------------------------------------------
  osm_diff_analyzer_if::analyzer_description_if * test_api_wrapper::get_test_api_description(void)
  {
    return new test_api_analyzer_description();
  }

  //----------------------------------------------------------------------------
  osm_diff_analyzer_if::general_analyzer_if * test_api_wrapper::create_test_api_analyzer(const osm_diff_analyzer_if::module_configuration * p_conf)
  {
    return new test_api_analyzer(p_conf,*m_common_api);
  }

  //----------------------------------------------------------------------------
  void test_api_wrapper::require_common_api(osm_diff_analyzer_if::module_library_if::t_register_function p_func)
  {
    m_common_api = new common_api(p_func);
  }

  //----------------------------------------------------------------------------
  void test_api_wrapper::cleanup(void)
  {
    delete m_common_api;
  }
  common_api * test_api_wrapper::m_common_api = NULL;

  extern "C"
  {
    void register_module(void** p_api,uint32_t p_api_size)
    {
      assert(p_api_size == MODULE_LIBRARY_IF_API_SIZE);
      std::cout << "Registration of test_api analyzer API " << std::endl ;
      p_api[osm_diff_analyzer_if::module_library_if::GET_API_VERSION] = (void*)test_api_wrapper::get_api_version;
      p_api[osm_diff_analyzer_if::module_library_if::GET_API_SIZE] = (void*)test_api_wrapper::get_api_size;
      p_api[osm_diff_analyzer_if::module_library_if::GET_DESCRIPTION] = (void*)test_api_wrapper::get_test_api_description;
      p_api[osm_diff_analyzer_if::module_library_if::CREATE_ANALYZER] = (void*)test_api_wrapper::create_test_api_analyzer;
      p_api[osm_diff_analyzer_if::module_library_if::REQUIRE_COMMON_API] = (void*)test_api_wrapper::require_common_api;
      p_api[osm_diff_analyzer_if::module_library_if::CLEAN_UP] = (void*)test_api_wrapper::cleanup;
    }
  }
}
//EOF
