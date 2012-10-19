#include "test_api_analyzer_description.h"

namespace osm_diff_analyzer_test_api
{
  //----------------------------------------------------------------------------
  const std::string & test_api_analyzer_description::get_input_type(void)const
  {
    return m_input_type;
  }

  //----------------------------------------------------------------------------
  const std::string & test_api_analyzer_description::get_output_type(void)const
  {
    return m_output_type;
  }

  //----------------------------------------------------------------------------
  const std::string & test_api_analyzer_description::get_type(void)const
  {
    return m_type;
  }

  const std::string test_api_analyzer_description::m_input_type = "sax";
  const std::string test_api_analyzer_description::m_output_type = "";
  const std::string test_api_analyzer_description::m_type = "test_api";

}
//EOF
