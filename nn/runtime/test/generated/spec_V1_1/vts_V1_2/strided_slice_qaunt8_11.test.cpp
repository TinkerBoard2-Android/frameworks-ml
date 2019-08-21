// Generated from strided_slice_qaunt8_11.mod.py
// DO NOT EDIT
// clang-format off
#include "GeneratedTests.h"

namespace generated_tests::strided_slice_qaunt8_11 {

std::vector<::test_helper::MixedTypedExample>& get_examples();

} // namespace generated_tests::strided_slice_qaunt8_11

namespace android::hardware::neuralnetworks::V1_2::generated_tests::strided_slice_qaunt8_11 {

Model createTestModel();
bool is_ignored(int);

TEST_F(NeuralnetworksHidlTest, strided_slice_qaunt8_11) {
  Execute(device,
          createTestModel,
          is_ignored,
          ::generated_tests::strided_slice_qaunt8_11::get_examples());
}

TEST_F(ValidationTest, strided_slice_qaunt8_11) {
  const Model model = createTestModel();
  const std::vector<Request> requests = createRequests(::generated_tests::strided_slice_qaunt8_11::get_examples());
  validateEverything(model, requests);
}

} // namespace android::hardware::neuralnetworks::V1_2::generated_tests::strided_slice_qaunt8_11

namespace generated_tests::strided_slice_qaunt8_11 {

std::vector<::test_helper::MixedTypedExample>& get_examples_dynamic_output_shape();

} // namespace generated_tests::strided_slice_qaunt8_11

namespace android::hardware::neuralnetworks::V1_2::generated_tests::strided_slice_qaunt8_11 {

Model createTestModel_dynamic_output_shape();
bool is_ignored_dynamic_output_shape(int);

TEST_F(DynamicOutputShapeTest, strided_slice_qaunt8_11_dynamic_output_shape) {
  Execute(device,
          createTestModel_dynamic_output_shape,
          is_ignored_dynamic_output_shape,
          ::generated_tests::strided_slice_qaunt8_11::get_examples_dynamic_output_shape(), true);
}

TEST_F(ValidationTest, strided_slice_qaunt8_11_dynamic_output_shape) {
  const Model model = createTestModel_dynamic_output_shape();
  const std::vector<Request> requests = createRequests(::generated_tests::strided_slice_qaunt8_11::get_examples_dynamic_output_shape());
  validateEverything(model, requests);
}

} // namespace android::hardware::neuralnetworks::V1_2::generated_tests::strided_slice_qaunt8_11

namespace generated_tests::strided_slice_qaunt8_11 {

std::vector<::test_helper::MixedTypedExample>& get_examples_all_inputs_as_internal();

} // namespace generated_tests::strided_slice_qaunt8_11

namespace android::hardware::neuralnetworks::V1_2::generated_tests::strided_slice_qaunt8_11 {

Model createTestModel_all_inputs_as_internal();
bool is_ignored_all_inputs_as_internal(int);

TEST_F(NeuralnetworksHidlTest, strided_slice_qaunt8_11_all_inputs_as_internal) {
  Execute(device,
          createTestModel_all_inputs_as_internal,
          is_ignored_all_inputs_as_internal,
          ::generated_tests::strided_slice_qaunt8_11::get_examples_all_inputs_as_internal());
}

TEST_F(ValidationTest, strided_slice_qaunt8_11_all_inputs_as_internal) {
  const Model model = createTestModel_all_inputs_as_internal();
  const std::vector<Request> requests = createRequests(::generated_tests::strided_slice_qaunt8_11::get_examples_all_inputs_as_internal());
  validateEverything(model, requests);
}

} // namespace android::hardware::neuralnetworks::V1_2::generated_tests::strided_slice_qaunt8_11

namespace generated_tests::strided_slice_qaunt8_11 {

std::vector<::test_helper::MixedTypedExample>& get_examples_all_inputs_as_internal_dynamic_output_shape();

} // namespace generated_tests::strided_slice_qaunt8_11

namespace android::hardware::neuralnetworks::V1_2::generated_tests::strided_slice_qaunt8_11 {

Model createTestModel_all_inputs_as_internal_dynamic_output_shape();
bool is_ignored_all_inputs_as_internal_dynamic_output_shape(int);

TEST_F(DynamicOutputShapeTest, strided_slice_qaunt8_11_all_inputs_as_internal_dynamic_output_shape) {
  Execute(device,
          createTestModel_all_inputs_as_internal_dynamic_output_shape,
          is_ignored_all_inputs_as_internal_dynamic_output_shape,
          ::generated_tests::strided_slice_qaunt8_11::get_examples_all_inputs_as_internal_dynamic_output_shape(), true);
}

TEST_F(ValidationTest, strided_slice_qaunt8_11_all_inputs_as_internal_dynamic_output_shape) {
  const Model model = createTestModel_all_inputs_as_internal_dynamic_output_shape();
  const std::vector<Request> requests = createRequests(::generated_tests::strided_slice_qaunt8_11::get_examples_all_inputs_as_internal_dynamic_output_shape());
  validateEverything(model, requests);
}

} // namespace android::hardware::neuralnetworks::V1_2::generated_tests::strided_slice_qaunt8_11

namespace generated_tests::strided_slice_qaunt8_11 {

std::vector<::test_helper::MixedTypedExample>& get_examples_all_tensors_as_inputs();

} // namespace generated_tests::strided_slice_qaunt8_11

namespace android::hardware::neuralnetworks::V1_2::generated_tests::strided_slice_qaunt8_11 {

Model createTestModel_all_tensors_as_inputs();
bool is_ignored_all_tensors_as_inputs(int);

TEST_F(NeuralnetworksHidlTest, strided_slice_qaunt8_11_all_tensors_as_inputs) {
  Execute(device,
          createTestModel_all_tensors_as_inputs,
          is_ignored_all_tensors_as_inputs,
          ::generated_tests::strided_slice_qaunt8_11::get_examples_all_tensors_as_inputs());
}

TEST_F(ValidationTest, strided_slice_qaunt8_11_all_tensors_as_inputs) {
  const Model model = createTestModel_all_tensors_as_inputs();
  const std::vector<Request> requests = createRequests(::generated_tests::strided_slice_qaunt8_11::get_examples_all_tensors_as_inputs());
  validateEverything(model, requests);
}

} // namespace android::hardware::neuralnetworks::V1_2::generated_tests::strided_slice_qaunt8_11

namespace generated_tests::strided_slice_qaunt8_11 {

std::vector<::test_helper::MixedTypedExample>& get_examples_all_tensors_as_inputs_dynamic_output_shape();

} // namespace generated_tests::strided_slice_qaunt8_11

namespace android::hardware::neuralnetworks::V1_2::generated_tests::strided_slice_qaunt8_11 {

Model createTestModel_all_tensors_as_inputs_dynamic_output_shape();
bool is_ignored_all_tensors_as_inputs_dynamic_output_shape(int);

TEST_F(DynamicOutputShapeTest, strided_slice_qaunt8_11_all_tensors_as_inputs_dynamic_output_shape) {
  Execute(device,
          createTestModel_all_tensors_as_inputs_dynamic_output_shape,
          is_ignored_all_tensors_as_inputs_dynamic_output_shape,
          ::generated_tests::strided_slice_qaunt8_11::get_examples_all_tensors_as_inputs_dynamic_output_shape(), true);
}

TEST_F(ValidationTest, strided_slice_qaunt8_11_all_tensors_as_inputs_dynamic_output_shape) {
  const Model model = createTestModel_all_tensors_as_inputs_dynamic_output_shape();
  const std::vector<Request> requests = createRequests(::generated_tests::strided_slice_qaunt8_11::get_examples_all_tensors_as_inputs_dynamic_output_shape());
  validateEverything(model, requests);
}

} // namespace android::hardware::neuralnetworks::V1_2::generated_tests::strided_slice_qaunt8_11

namespace generated_tests::strided_slice_qaunt8_11 {

std::vector<::test_helper::MixedTypedExample>& get_examples_all_tensors_as_inputs_all_inputs_as_internal();

} // namespace generated_tests::strided_slice_qaunt8_11

namespace android::hardware::neuralnetworks::V1_2::generated_tests::strided_slice_qaunt8_11 {

Model createTestModel_all_tensors_as_inputs_all_inputs_as_internal();
bool is_ignored_all_tensors_as_inputs_all_inputs_as_internal(int);

TEST_F(NeuralnetworksHidlTest, strided_slice_qaunt8_11_all_tensors_as_inputs_all_inputs_as_internal) {
  Execute(device,
          createTestModel_all_tensors_as_inputs_all_inputs_as_internal,
          is_ignored_all_tensors_as_inputs_all_inputs_as_internal,
          ::generated_tests::strided_slice_qaunt8_11::get_examples_all_tensors_as_inputs_all_inputs_as_internal());
}

TEST_F(ValidationTest, strided_slice_qaunt8_11_all_tensors_as_inputs_all_inputs_as_internal) {
  const Model model = createTestModel_all_tensors_as_inputs_all_inputs_as_internal();
  const std::vector<Request> requests = createRequests(::generated_tests::strided_slice_qaunt8_11::get_examples_all_tensors_as_inputs_all_inputs_as_internal());
  validateEverything(model, requests);
}

} // namespace android::hardware::neuralnetworks::V1_2::generated_tests::strided_slice_qaunt8_11

namespace generated_tests::strided_slice_qaunt8_11 {

std::vector<::test_helper::MixedTypedExample>& get_examples_all_tensors_as_inputs_all_inputs_as_internal_dynamic_output_shape();

} // namespace generated_tests::strided_slice_qaunt8_11

namespace android::hardware::neuralnetworks::V1_2::generated_tests::strided_slice_qaunt8_11 {

Model createTestModel_all_tensors_as_inputs_all_inputs_as_internal_dynamic_output_shape();
bool is_ignored_all_tensors_as_inputs_all_inputs_as_internal_dynamic_output_shape(int);

TEST_F(DynamicOutputShapeTest, strided_slice_qaunt8_11_all_tensors_as_inputs_all_inputs_as_internal_dynamic_output_shape) {
  Execute(device,
          createTestModel_all_tensors_as_inputs_all_inputs_as_internal_dynamic_output_shape,
          is_ignored_all_tensors_as_inputs_all_inputs_as_internal_dynamic_output_shape,
          ::generated_tests::strided_slice_qaunt8_11::get_examples_all_tensors_as_inputs_all_inputs_as_internal_dynamic_output_shape(), true);
}

TEST_F(ValidationTest, strided_slice_qaunt8_11_all_tensors_as_inputs_all_inputs_as_internal_dynamic_output_shape) {
  const Model model = createTestModel_all_tensors_as_inputs_all_inputs_as_internal_dynamic_output_shape();
  const std::vector<Request> requests = createRequests(::generated_tests::strided_slice_qaunt8_11::get_examples_all_tensors_as_inputs_all_inputs_as_internal_dynamic_output_shape());
  validateEverything(model, requests);
}

} // namespace android::hardware::neuralnetworks::V1_2::generated_tests::strided_slice_qaunt8_11
