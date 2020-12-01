#define CPPHTTPLIB_OPENSSL_SUPPORT
#include <string>
#include <httplib.h>
#include <aocmaxnoe2020.h>

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

std::vector<std::string> split_lines(std::string input) {
    std::vector<std::string> lines;
    std::stringstream stream(input);
    std::string line;

    while (std::getline(stream, line)) {
        lines.push_back(line);
    }

    return lines;
}


}
