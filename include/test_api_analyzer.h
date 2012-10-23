#ifndef _TEST_API_ANALYZER_H_
#define _TEST_API_ANALYZER_H_

#include "sax_analyzer_base.h"
#include "test_api_analyzer_description.h"
#include "stdint.h"
#include <map>
#include <fstream>

namespace osm_diff_analyzer_test_api
{
  class common_api;

  class test_api_analyzer:public osm_diff_analyzer_sax_if::sax_analyzer_base
  {
  public:
    test_api_analyzer(const std::string & p_name,common_api * p_api);
    ~test_api_analyzer(void);
    // Methods inherited from sax_analyzer_if
    void init(void);
    void start_element(const std::string & p_name);
    void get_attribute(const std::string & p_name,const std::string & p_value);
    void end_element(const std::string & p_name);
    const std::string & get_input_type(void)const;
    const std::string & get_output_type(void)const;
    const std::string & get_type(void)const;
    // End of inherited methods
  private:
    common_api * m_api;
    bool m_done;
     static test_api_analyzer_description m_description;
 };
}
#endif
