//
// Created by daniel on 4/25/18.
//

#ifndef CFLOP_INPUT_H
#define CFLOP_INPUT_H

#include "../Request.h"
#include "../extract_helper.h"
#include "../request_types.h"
#include "../../../libs/json/single_include/nlohmann/json.hpp"
using json = nlohmann::json;


namespace nlohmann {

//    just pipe a json into a request object and you either get a valid Request or nothing

    template<>
    struct adl_serializer<std::optional<Request>> {

        static void to_json(json &j, const std::optional<Request> &req) {};

        static void from_json(const json &j, std::optional<Request> &req) {
            req_type reqType = make_req_type(j);

            try {
                switch (reqType) {
                    case INVALID_TYPE:
                        req = std::nullopt;
                        break;
                    case NODES_POST:
                        req = Request(NODES_POST, NODE, POST, nodes_post_s{});
                        break;
                    case NODES_DELETE:
                        auto id_d = j.at("nodes").at("delete").at("id").get<size_t>();
                        req = Request(NODES_DELETE, NODE, DELETE, nodes_delete_s{id_d});
                        break;
                    case NODES_GET:
                        auto id_g = j.at("nodes").at("get").at("id").get<size_t>();
                        req = Request(NODES_GET, NODE, GET, nodes_get_s{id_g});
                        break;
                    case NODES_PUT_START:
                        auto id_put_s = j.at("nodes").at("put").at("start").at("id").get<size_t>();
                        req = Request(NODES_PUT_START, NODE, PUT, nodes_put_start_s{id_put_s});
                        break;
                    case NODES_PUT_END:
                        auto id_put_e = j.at("nodes").at("put").at("end").at("id").get<size_t>();
                        req = Request(NODES_PUT_END, NODE, PUT, nodes_put_end_s{id_put_e});
                        break;
                    case EDGES_GET:
                        auto id_get_ed = j.at("edges").at("get").at("id").get<size_t>();
                        req = Request(EDGES_GET, EDGE, GET, edges_get_s{id_get_ed});
                        break;
                    case EDGES_POST:
                        auto id_post_ed = j.at("edges").at("post").at("id").get<size_t>();
                        req = Request(EDGES_POST, EDGE, POST, edges_post_s{id_post_ed});
                        break;
                    case EDGES_DELETE:
                        auto id_delete_ed = j.at("edges").at("delete").at("id").get<size_t>();
                        req = Request(EDGES_DELETE, EDGE, DELETE, edges_delete_s{id_delete_ed});
                        break;
                    case STATE_GET:
                        req = Request(STATE_GET, STATE, GET, state_get_s{});
                        break;
                    case STATE_POST:
                        auto nodes = j.at("state").at("post").at("state").at("nodes").get<std::vector<node>>();
                        auto edges = j.at("state").at("post").at("state").at("edges").get<std::vector<edges>>();
                        auto active = j.at("state").at("post").at("state").at("active").get<size_t>();
                        auto start = j.at("state").at("post").at("state").at("start").get<size_t>();
                        auto end = j.at("state").at("post").at("state").at("end").get<size_t>();
                        state_post_s sp_s{nodes, edges, active, start, end};

                        req = Request(STATE_POST, STATE, POST, sp_s);
                        break;
                    case STATE_PUT:
                        auto input = j.at("state").at("put").at("input").get<std::string>();
                        req = Request(STATE_PUT, STATE, PUT, state_put_s{input});
                        break;
                }
            } catch (std::exception &e) {
                req = std::nullopt;
            }
        }
    };
}


#endif //CFLOP_INPUT_H
