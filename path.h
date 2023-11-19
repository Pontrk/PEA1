#ifndef PEA1_PATH_H
#define PEA1_PATH_H

#include <vector>
#include <string>

class Path {
        public:
        std::vector<int> path_;
        int cost_;

        Path();
        Path(std::vector<int> path, int cost);
        ~Path() = default;

        void add_to_path(int node, int cost);
        int get_prev_city() const;
        std::string to_string() const;

        private:
        std::string get_path_str() const;
        std::string get_cost_str() const;
};


#endif //PEA1_PATH_H
