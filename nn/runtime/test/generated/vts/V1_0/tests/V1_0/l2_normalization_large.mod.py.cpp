// Generated from l2_normalization_large.mod.py
// DO NOT EDIT
// clang-format off
#include "GeneratedTests.h"

namespace generated_tests::l2_normalization_large {

std::vector<::test_helper::MixedTypedExample>& get_examples();

} // namespace generated_tests::l2_normalization_large

namespace android::hardware::neuralnetworks::V1_0::generated_tests::l2_normalization_large {

Model createTestModel();
bool is_ignored(int);

TEST_F(NeuralnetworksHidlTest, l2_normalization_large) {
  Execute(device,
          createTestModel,
          is_ignored,
          ::generated_tests::l2_normalization_large::get_examples());
}

TEST_F(ValidationTest, l2_normalization_large) {
  const Model model = createTestModel();
  const std::vector<Request> requests = createRequests(::generated_tests::l2_normalization_large::get_examples());
  validateEverything(model, requests);
}

} // namespace android::hardware::neuralnetworks::V1_0::generated_tests::l2_normalization_large

