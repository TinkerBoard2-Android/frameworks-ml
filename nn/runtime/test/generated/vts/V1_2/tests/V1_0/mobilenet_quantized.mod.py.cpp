// Generated from mobilenet_quantized.mod.py
// DO NOT EDIT
// clang-format off
#include "GeneratedTests.h"

namespace generated_tests::mobilenet_quantized {

std::vector<::test_helper::MixedTypedExample>& get_examples();

} // namespace generated_tests::mobilenet_quantized

namespace android::hardware::neuralnetworks::V1_2::generated_tests::mobilenet_quantized {

Model createTestModel();
bool is_ignored(int);

TEST_F(NeuralnetworksHidlTest, mobilenet_quantized) {
  Execute(device,
          createTestModel,
          is_ignored,
          ::generated_tests::mobilenet_quantized::get_examples());
}

TEST_F(ValidationTest, mobilenet_quantized) {
  const Model model = createTestModel();
  const std::vector<Request> requests = createRequests(::generated_tests::mobilenet_quantized::get_examples());
  validateEverything(model, requests);
}

} // namespace android::hardware::neuralnetworks::V1_2::generated_tests::mobilenet_quantized

namespace generated_tests::mobilenet_quantized {

std::vector<::test_helper::MixedTypedExample>& get_examples_dynamic_output_shape();

} // namespace generated_tests::mobilenet_quantized

namespace android::hardware::neuralnetworks::V1_2::generated_tests::mobilenet_quantized {

Model createTestModel_dynamic_output_shape();
bool is_ignored_dynamic_output_shape(int);

TEST_F(DynamicOutputShapeTest, mobilenet_quantized_dynamic_output_shape) {
  Execute(device,
          createTestModel_dynamic_output_shape,
          is_ignored_dynamic_output_shape,
          ::generated_tests::mobilenet_quantized::get_examples_dynamic_output_shape(), true);
}

TEST_F(ValidationTest, mobilenet_quantized_dynamic_output_shape) {
  const Model model = createTestModel_dynamic_output_shape();
  const std::vector<Request> requests = createRequests(::generated_tests::mobilenet_quantized::get_examples_dynamic_output_shape());
  validateEverything(model, requests);
}

} // namespace android::hardware::neuralnetworks::V1_2::generated_tests::mobilenet_quantized

