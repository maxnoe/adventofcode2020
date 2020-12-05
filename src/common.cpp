#define CPPHTTPLIB_OPENSSL_SUPPORT
#include <string>
#include <httplib.h>
#include <aocmaxnoe2020/aocmaxnoe2020.h>

namespace aocmaxnoe2020 {


const std::string URL = "https://adventofcode.com";


std::string get_input(int day) {
    httplib::Client client(URL.c_str());
    client.set_follow_location(true);

    char* tmp = std::getenv("AOC_SESSION");
    if (tmp == nullptr) {
        throw std::runtime_error("You need to set the AOC_SESSION env variable with your cookie");
    }

    std::string session(tmp);

    httplib::Headers headers = {
        {"Cookie", "session=" + session}
    };

    const std::string path = "/2020/day/" + std::to_string(day) + "/input";
    auto res = client.Get(path.c_str(), headers);
    if (res->status != 200) {
        throw std::runtime_error("Could not download input: {}" + res->body);
    }

    return res->body;
}

std::vector<std::string_view> split(std::string_view str, std::string_view delimiter, bool include_empty) {
    std::vector<std::string_view> parts;

    size_t pos = 0;
    while ((pos = str.find(delimiter)) != std::string::npos) {
        parts.emplace_back(str.substr(0, pos));
        str.remove_prefix(pos + delimiter.length());
    }

    if (str != "" || include_empty) {
        parts.emplace_back(str);
    }

    return parts;
}

std::vector<std::string_view> split_lines(std::string_view input) {
    return split(input, "\n", false);
}


}
