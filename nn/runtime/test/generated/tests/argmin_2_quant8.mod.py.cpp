// DO NOT EDIT;
// Generated by ml/nn/runtime/test/specs/generate_test.sh
#include "../../TestGenerated.h"

namespace argmin_2_quant8 {
std::vector<MixedTypedExample> examples = {
// Generated argmin_2_quant8 test
#include "generated/examples/argmin_2_quant8.example.cpp"
};
// Generated model constructor
#include "generated/models/argmin_2_quant8.model.cpp"
} // namespace argmin_2_quant8
TEST_F(GeneratedTests, argmin_2_quant8) {
    execute(argmin_2_quant8::CreateModel,
            argmin_2_quant8::is_ignored,
            argmin_2_quant8::examples);
}
