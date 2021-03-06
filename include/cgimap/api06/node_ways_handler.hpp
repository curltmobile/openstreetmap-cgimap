#ifndef API06_NODE_WAYS_HANDLER_HPP
#define API06_NODE_WAYS_HANDLER_HPP

#include "cgimap/handler.hpp"
#include "cgimap/osm_current_responder.hpp"
#include "cgimap/request.hpp"
#include <string>

namespace api06 {

class node_ways_responder : public osm_current_responder {
public:
  node_ways_responder(mime::type, osm_id_t, factory_ptr &);
  ~node_ways_responder();

private:
  osm_id_t id;

  void check_visibility();
};

class node_ways_handler : public handler {
public:
  node_ways_handler(request &req, osm_id_t id);
  ~node_ways_handler();

  std::string log_name() const;
  responder_ptr_t responder(factory_ptr &x) const;

private:
  osm_id_t id;
};

} // namespace api06

#endif /* API06_NODE_WAYS_HANDLER_HPP */
