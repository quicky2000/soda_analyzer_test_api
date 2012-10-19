#ifndef _TEST_API_WRAPPER_H_
#define _TEST_API_WRAPPER_H_

#include "general_analyzer_if.h"
#include "module_library_if.h"

#include <stdint.h>
namespace osm_diff_analyzer_test_api
{
  class common_api;

  class test_api_wrapper
  {
  public:
    static const char * get_api_version(void);
    static uint32_t get_api_size(void);
    static osm_diff_analyzer_if::analyzer_description_if * get_test_api_description(void);
    static osm_diff_analyzer_if::general_analyzer_if * create_test_api_analyzer(const std::string & p_name);
    static void require_common_api(osm_diff_analyzer_if::module_library_if::t_register_function);
    static void cleanup(void);
  private:
    static common_api *m_common_api;
  };

}
#endif // _TEST_API_WRAPPER_H_
//EOF
