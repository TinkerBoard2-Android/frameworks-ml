// Generated from depthwise_conv2d_float_large_2_weights_as_inputs.mod.py
// DO NOT EDIT
// clang-format off
#include "GeneratedTests.h"

namespace generated_tests::depthwise_conv2d_float_large_2_weights_as_inputs {

std::vector<::test_helper::MixedTypedExample>& get_examples();

} // namespace generated_tests::depthwise_conv2d_float_large_2_weights_as_inputs

namespace android::hardware::neuralnetworks::V1_0::generated_tests::depthwise_conv2d_float_large_2_weights_as_inputs {

Model createTestModel();
bool is_ignored(int);

TEST_F(NeuralnetworksHidlTest, depthwise_conv2d_float_large_2_weights_as_inputs) {
  Execute(device,
          createTestModel,
          is_ignored,
          ::generated_tests::depthwise_conv2d_float_large_2_weights_as_inputs::get_examples());
}

TEST_F(ValidationTest, depthwise_conv2d_float_large_2_weights_as_inputs) {
  const Model model = createTestModel();
  const std::vector<Request> requests = createRequests(::generated_tests::depthwise_conv2d_float_large_2_weights_as_inputs::get_examples());
  validateEverything(model, requests);
}

} // namespace android::hardware::neuralnetworks::V1_0::generated_tests::depthwise_conv2d_float_large_2_weights_as_inputs

