#include "test_api_analyzer.h"
#include "common_api.h"
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <cstring>
#include <cassert>

namespace osm_diff_analyzer_test_api
{
  //------------------------------------------------------------------------------
  test_api_analyzer::test_api_analyzer(const std::string & p_name,common_api * p_api):
    osm_diff_analyzer_sax_if::sax_analyzer_base("user_analyser",p_name,""),
    m_api(p_api)
  {
    assert(m_api);
    // Get Node
    std::cout << "========================" << std::endl ;
    std::cout << "GET Node 474827214" << std::endl ;
    std::cout << "========================" << std::endl ;
    const osm_api_data_types::osm_node * l_node = m_api->get_node(474827214);
    assert(l_node);
    std::cout << *l_node ; 
    delete l_node;
    std::cout << "------------------------" << std::endl ;

    // Get Node version
    std::cout << "========================" << std::endl ;
    std::cout << "GET Node 474827214 version 1" << std::endl ;
    std::cout << "========================" << std::endl ;
    l_node = m_api->get_node_version(474827214,1);
    assert(l_node);
    std::cout << *l_node ; 
    delete l_node;
    std::cout << "------------------------" << std::endl ;
   
    // Get Node history
    std::cout << "========================" << std::endl ;
    std::cout << "GET Node 474827214 history" << std::endl ;
    std::cout << "========================" << std::endl ;
    const std::vector<osm_api_data_types::osm_node *> * const l_node_history = m_api->get_node_history(474827214);
    for(std::vector<osm_api_data_types::osm_node *>::const_iterator l_iter = l_node_history->begin();
	l_iter != l_node_history->end();
	++l_iter)
      {
	std::cout << "-------------------------------" << std::endl ;
	std::cout << *(*l_iter) << std::endl ;
	delete *l_iter;
      }
    delete l_node_history;
    std::cout << "------------------------" << std::endl ;
   
    // Get all ways for a node shared by Rue des martyrs and Rampe provisoire
    std::cout << "========================" << std::endl ;
    std::cout << "GET ways using Node 1947164927" << std::endl ;
    std::cout << "========================" << std::endl ;
    const std::vector<osm_api_data_types::osm_way *> * const l_ways = m_api->get_node_ways(1947164927);
    for(std::vector<osm_api_data_types::osm_way *>::const_iterator l_iter = l_ways->begin();
        l_iter != l_ways->end();
        ++l_iter)
      {
        std::cout << "-------------------------------" << std::endl ;
        std::cout << *(*l_iter) << std::endl ;
        delete *l_iter;
      }
    delete l_ways;

    // Get all relations using bus stop victor hugo
    std::cout << "========================" << std::endl ;
    std::cout << "GET relations using Node 1829038636" << std::endl ;
    std::cout << "========================" << std::endl ;
    const std::vector<osm_api_data_types::osm_relation *> * const l_node_relations = m_api->get_node_relations(1829038636);
    for(std::vector<osm_api_data_types::osm_relation *>::const_iterator l_iter = l_node_relations->begin();
        l_iter != l_node_relations->end();
        ++l_iter)
      {
        std::cout << "-------------------------------" << std::endl ;
        std::cout << *(*l_iter) << std::endl ;
        delete *l_iter;
      }
    delete l_node_relations;

    // Get list of nodes
    std::vector<osm_api_data_types::osm_object::t_osm_id> l_node_ids;
    l_node_ids.push_back(344567058);
    l_node_ids.push_back(474827214);
    std::cout << "========================" << std::endl ;
    std::cout << "GET Nodes (344567058,474827214)" << std::endl ;
    std::cout << "========================" << std::endl ;
    const std::vector<osm_api_data_types::osm_node*> * l_list_node = m_api->get_nodes(l_node_ids);
    for(std::vector<osm_api_data_types::osm_node*>::const_iterator l_iter = l_list_node->begin();
	l_iter != l_list_node->end();
	++l_iter)
      {
	std::cout << **l_iter;
	delete *l_iter;
      }
    delete l_list_node;
    std::cout << "------------------------" << std::endl ;

  // Get way version
    std::cout << "========================" << std::endl ;
    std::cout << "GET way 173118043" << std::endl ;
    std::cout << "========================" << std::endl ;
    const osm_api_data_types::osm_way * l_way = m_api->get_way(173118043);
    assert(l_way);
    std::cout << *l_way ; 
    delete l_way;
    std::cout << "------------------------" << std::endl ;
 
  // Get way version
    std::cout << "========================" << std::endl ;
    std::cout << "GET way 173118043  version 1" << std::endl ;
    std::cout << "========================" << std::endl ;
    l_way = m_api->get_way_version(173118043,1);
    assert(l_way);
    std::cout << *l_way ; 
    delete l_way;
    std::cout << "------------------------" << std::endl ;
 
    // Get Way history
    std::cout << "========================" << std::endl ;
    std::cout << "GET Way 173118043 history" << std::endl ;
    std::cout << "========================" << std::endl ;
    const std::vector<osm_api_data_types::osm_way *> * const l_way_history = m_api->get_way_history(173118043);
    for(std::vector<osm_api_data_types::osm_way *>::const_iterator l_iter = l_way_history->begin();
	l_iter != l_way_history->end();
	++l_iter)
      {
	std::cout << "-------------------------------" << std::endl ;
	std::cout << *(*l_iter) << std::endl ;
	delete *l_iter;
      }
    delete l_way_history;
    std::cout << "------------------------" << std::endl ;
   
  // Get all relations using way Rampe Provisoire
    std::cout << "========================" << std::endl ;
    std::cout << "GET Relations using Way 184257352" << std::endl ;
    std::cout << "========================" << std::endl ;
    const std::vector<osm_api_data_types::osm_relation *> * const l_way_relations = m_api->get_way_relations(184257352);
    for(std::vector<osm_api_data_types::osm_relation *>::const_iterator l_iter = l_way_relations->begin();
        l_iter != l_way_relations->end();
        ++l_iter)
      {
        std::cout << "-------------------------------" << std::endl ;
        std::cout << *(*l_iter) << std::endl ;
        delete *l_iter;
      }
    delete l_way_relations;
  std::cout << "--------------------------------" << std::endl ;

  // Get full way
  std::cout << "========================" << std::endl ;
  std::cout << "GET full Way 173118043" << std::endl ;
  std::cout << "========================" << std::endl ;
  std::vector<osm_api_data_types::osm_node*> l_way_nodes;
  const osm_api_data_types::osm_way * l_full_way = m_api->get_way_full(173118043,l_way_nodes);
  assert(l_full_way);
  std::cout << *l_full_way ; 
  for(std::vector<osm_api_data_types::osm_node*>::const_iterator l_iter = l_way_nodes.begin();
      l_iter != l_way_nodes.end();
      ++l_iter)
    {
      std::cout << **l_iter;
      delete *l_iter;
    }
  delete l_full_way;
  std::cout << "--------------------------------" << std::endl ;

  std::cout << "--------------------------------" << std::endl ;
    // Get list of ways
    std::cout << "========================" << std::endl ;
    std::cout << "GET Ways(173118043,184257352)" << std::endl ;
    std::cout << "========================" << std::endl ;
    std::vector<osm_api_data_types::osm_object::t_osm_id> l_way_ids;
    l_way_ids.push_back(173118043);
    l_way_ids.push_back(184257352);
    const std::vector<osm_api_data_types::osm_way*> * l_list_way = m_api->get_ways(l_way_ids);
    for(std::vector<osm_api_data_types::osm_way*>::const_iterator l_iter = l_list_way->begin();
	l_iter != l_list_way->end();
	++l_iter)
      {
	std::cout << **l_iter;
	delete *l_iter;
      }
    delete l_list_way;
    std::cout << "------------------------" << std::endl ;

    // Get relation for bus line 30
    std::cout << "========================" << std::endl ;
    std::cout << "GET relation 216546" << std::endl ;
    std::cout << "========================" << std::endl ;
    const osm_api_data_types::osm_relation * l_relation = m_api->get_relation(216546);
    assert(l_relation);
    std::cout << * l_relation << std::endl ;
    delete l_relation;

    // Get relation for bus line 30
    std::cout << "========================" << std::endl ;
    std::cout << "GET relation 216546 version 1" << std::endl ;
    std::cout << "========================" << std::endl ;
    l_relation = m_api->get_relation_version(216546,1);
    assert(l_relation);
    std::cout << * l_relation << std::endl ;
    delete l_relation;

    // Get Relation history
    std::cout << "========================" << std::endl ;
    std::cout << "GET Relation 216546 history" << std::endl ;
    std::cout << "========================" << std::endl ;
    const std::vector<osm_api_data_types::osm_relation *> * const l_relation_history = m_api->get_relation_history(216546);
    for(std::vector<osm_api_data_types::osm_relation *>::const_iterator l_iter = l_relation_history->begin();
	l_iter != l_relation_history->end();
	++l_iter)
      {
	std::cout << "-------------------------------" << std::endl ;
	std::cout << *(*l_iter) << std::endl ;
	delete *l_iter;
      }
    delete l_relation_history;
    std::cout << "------------------------" << std::endl ;
   
  // Get full relation for bus line 30
    std::cout << "========================" << std::endl ;
    std::cout << "GET full Relation 216546" << std::endl ;
    std::cout << "========================" << std::endl ;
  std::vector<osm_api_data_types::osm_node*> l_relation_nodes;
  std::vector<osm_api_data_types::osm_way*> l_relation_ways;
  const osm_api_data_types::osm_relation * l_full_relation = m_api->get_relation_full(216546,l_relation_nodes,l_relation_ways);
  assert(l_relation);
  std::cout << * l_full_relation << std::endl ;
  delete l_full_relation;
  for(std::vector<osm_api_data_types::osm_node*>::const_iterator l_iter = l_relation_nodes.begin();
      l_iter != l_relation_nodes.end();
      ++l_iter)
    {
      std::cout << **l_iter;
      delete *l_iter;
    }
  for(std::vector<osm_api_data_types::osm_way*>::const_iterator l_iter = l_relation_ways.begin();
      l_iter != l_relation_ways.end();
      ++l_iter)
    {
      std::cout << **l_iter;
      delete *l_iter;
    }
  std::cout << "--------------------------------" << std::endl ;

  // Get list of relations
  std::cout << "========================" << std::endl ;
  std::cout << "GET Relations(216546,191189)" << std::endl ;
  std::cout << "========================" << std::endl ;
  std::vector<osm_api_data_types::osm_object::t_osm_id> l_relation_ids;
  l_relation_ids.push_back(216546);
  l_relation_ids.push_back(191189);
  const std::vector<osm_api_data_types::osm_relation*> * l_list_relation = m_api->get_relations(l_relation_ids);
  for(std::vector<osm_api_data_types::osm_relation*>::const_iterator l_iter = l_list_relation->begin();
      l_iter != l_list_relation->end();
      ++l_iter)
    {
      std::cout << **l_iter;
      delete *l_iter;
    }
  delete l_list_relation;
  std::cout << "------------------------" << std::endl ;

  // Get changeset
  std::cout << "========================" << std::endl ;
  std::cout << "GET changeset 13369487" << std::endl ;
  std::cout << "========================" << std::endl ;
  const osm_api_data_types::osm_changeset * l_changeset = m_api->get_changeset(13369487);
  assert(l_changeset);
  std::cout << *l_changeset;
  delete l_changeset;
  std::cout << "------------------------" << std::endl ;

  // Get changeset content
  std::cout << "========================" << std::endl ;
  std::cout << "GET changeset content 13369487" << std::endl ;
  std::cout << "========================" << std::endl ;
  const std::vector<osm_api_data_types::osm_change *> * l_changes = m_api->get_changeset_content(13369487);
  for(std::vector<osm_api_data_types::osm_change*>::const_iterator l_iter = l_changes->begin();
      l_iter != l_changes->end();
      ++l_iter)
    {
      std::cout << **l_iter;
      delete *l_iter;
    }
  delete l_changes;
  std::cout << "------------------------" << std::endl ;

  // Get changesets of quicky
  std::cout << "========================" << std::endl ;
  std::cout << "GET changesets of quicky since 2012-09-07T14:02:41Z" << std::endl ;
  std::cout << "========================" << std::endl ;
  const std::vector<osm_api_data_types::osm_changeset*> * l_list_changeset = m_api->get_changesets(osm_api_data_types::osm_bounding_box(),0,"quicky","2012-09-07T14:02:41Z","",false,false);
  for(std::vector<osm_api_data_types::osm_changeset*>::const_iterator l_iter = l_list_changeset->begin();
      l_iter != l_list_changeset->end();
      ++l_iter)
    {
      std::cout << **l_iter;
      delete *l_iter;
    }
  delete l_list_changeset;
  std::cout << "------------------------" << std::endl ;

  //Get map elements
  std::cout << "========================" << std::endl ;
  std::cout << "GET map objects from (5.7076801,45.1925595,5.7112314,45.2000492)" << std::endl ;
  std::cout << "========================" << std::endl ;
  std::vector<osm_api_data_types::osm_node*> l_map_nodes;
  std::vector<osm_api_data_types::osm_way*> l_map_ways;
  std::vector<osm_api_data_types::osm_relation*> l_map_relations;
  m_api->get_map(osm_api_data_types::osm_bounding_box(5.7076801,45.1925595,5.7112314,45.2000492),l_map_nodes,l_map_ways,l_map_relations);
  for(std::vector<osm_api_data_types::osm_node*>::const_iterator l_iter = l_map_nodes.begin();
      l_iter != l_map_nodes.end();
      ++l_iter)
    {
      std::cout << **l_iter;
      delete *l_iter;
    }
  for(std::vector<osm_api_data_types::osm_way*>::const_iterator l_iter = l_map_ways.begin();
      l_iter != l_map_ways.end();
      ++l_iter)
    {
      std::cout << **l_iter;
      delete *l_iter;
    }
  for(std::vector<osm_api_data_types::osm_relation*>::const_iterator l_iter = l_map_relations.begin();
      l_iter != l_map_relations.end();
      ++l_iter)
    {
      std::cout << **l_iter;
      delete *l_iter;
    }
  std::cout << "------------------------" << std::endl ;
  exit(-1);
  }

  //------------------------------------------------------------------------------
  test_api_analyzer::~test_api_analyzer(void)
  {
  }

  //------------------------------------------------------------------------------
  void test_api_analyzer::init(void)
  {
  }

  //------------------------------------------------------------------------------
  void test_api_analyzer::start_element(const std::string & p_name)
  {
  }

  //------------------------------------------------------------------------------
  void test_api_analyzer::end_element(const std::string & p_name)
  {
  }

  //------------------------------------------------------------------------------
  void test_api_analyzer::get_attribute(const std::string & p_name,const std::string & p_value)
  {
  }

}
//EOF
