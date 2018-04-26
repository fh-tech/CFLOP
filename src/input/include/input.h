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

        static void to_json(json& j, const std::optional<Request>& req){};

        static void from_json(const json& j, std::optional<Request>& req){
            req_type reqType = make_req_type(j);

            try {
                switch(reqType) {
                    case INVALID_TYPE:
                        //endpoint und method implizit setzen
                        break;
                    case NODES_POST:

                        Request(NODES_POST, )
                        break;
                    case NODES_DELETE:
                        break;
                    case NODES_GET:
                        break;
                    case NODES_PUT_START:
                        break;
                    case NODES_PUT_END:
                        break;
                    case EDGES_GET:
                        break;
                    case EDGES_POST:
                        break;
                    case EDGES_DELETE:
                        break;
                    case STATE_GET:
                        break;
                    case STATE_POST:
                        break;
                    case STATE_PUT:
                        break;
                }
            }
        } catch(std::exception& e) {
            // set empty optional
        }

    };

}


#endif //CFLOP_INPUT_H
