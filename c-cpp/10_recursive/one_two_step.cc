#include <iostream>
#include <unordered_map>

class SolutionOFOneTwoStep {
  private:
    static std::unordered_map<size_t, size_t> result_;

  public:
    size_t operator()(size_t steps) {
        auto iter = result_.find(steps);
        if (result_.end() != iter) {  // found.
            return iter->second;
        } else {
            size_t res = operator()(steps - 1) + operator()(steps - 2);
            result_.insert({steps, res});
            return res;
        }
    }
};

std::unordered_map<size_t, size_t>
    SolutionOFOneTwoStep::result_ = {{1, 1}, {2, 2}};

int main() {
    std::cout << SolutionOFOneTwoStep()(10) << std::endl;
    return 0;
}
