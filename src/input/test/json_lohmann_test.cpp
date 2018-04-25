#include <gtest/gtest.h>
#include <input.h>

using json = nlohmann::json;

/**
 * Escaped string for json library
 */
TEST(json, test1) {
    json j = R"(
      {
        "happy": true,
        "pi": 3.141
      }
    )"_json;
    ASSERT_EQ(j["happy"], true);
    ASSERT_EQ(j["pi"], 3.141);
}

TEST(json, test2) {
    json j = json::object();
    j["ar"] = {1, 2, "foo"};
    j["ar"].push_back("bar");

    ASSERT_TRUE(1 == j.size());
    ASSERT_TRUE(4 == j["ar"].size());
    j.clear();
    ASSERT_TRUE(j.empty());
}

/**
 * Deserialize a input json (works like this with cin!
 */
TEST(json, test3) {
    std::string input = "{\"happy\":true,\"pi\":3.141}";
    std::istringstream inputS(input);

    json j;
    inputS >> j;

    ASSERT_EQ(j["happy"], true);
    ASSERT_EQ(j["pi"], 3.141);
}

/**
 * Deserialize NODE PUT/START (setting a node with given ID as starting point
 */
TEST(json, test4) {
    std::string input = "{\"nodes\":{\"put\":{\"start\":{\"id\": 0 }}}}";
    std::istringstream inputS;
    inputS.str(input);

    json j;
    inputS >> j;

    ASSERT_EQ(j["nodes"]["put"]["start"]["id"], 0);
    ASSERT_FALSE(3 == j["nodes"]["put"]["start"]["id"]);
}
