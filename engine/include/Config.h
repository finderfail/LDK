#ifndef CONFIG_H
#define CONFIG_H

#include <string>
#include <unordered_map>
#include <vector>

class Config {
public:
    Config();
    ~Config();
    bool load(const std::string& filename);
    std::string get(const std::string& key) const;
    int getInt(const std::string& key) const;
    void set(const std::string& key, const std::string& value);
    void setInt(const std::string& key, int value);
private:
    std::unordered_map<std::string, std::string> configData_;
};

#endif