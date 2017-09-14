// Generated file (from: lstm3.mod.py). Do not edit
void CreateModel(Model *model) {
  OperandType type5(Type::TENSOR_FLOAT32, {0,0});
  OperandType type3(Type::TENSOR_FLOAT32, {0});
  OperandType type7(Type::TENSOR_FLOAT32, {1});
  OperandType type9(Type::TENSOR_FLOAT32, {2, 16});
  OperandType type8(Type::TENSOR_FLOAT32, {2, 20, 4});
  OperandType type10(Type::TENSOR_FLOAT32, {2, 20});
  OperandType type0(Type::TENSOR_FLOAT32, {2, 5});
  OperandType type2(Type::TENSOR_FLOAT32, {20, 16});
  OperandType type1(Type::TENSOR_FLOAT32, {20, 5});
  OperandType type4(Type::TENSOR_FLOAT32, {20});
  OperandType type6(Type::TENSOR_INT32, {1});
  // Phase 1, operands
  auto input = model->addOperand(&type0);
  auto input_to_input_weights = model->addOperand(&type1);
  auto input_to_forget_weights = model->addOperand(&type1);
  auto input_to_cell_weights = model->addOperand(&type1);
  auto input_to_output_weights = model->addOperand(&type1);
  auto recurrent_to_intput_weights = model->addOperand(&type2);
  auto recurrent_to_forget_weights = model->addOperand(&type2);
  auto recurrent_to_cell_weights = model->addOperand(&type2);
  auto recurrent_to_output_weights = model->addOperand(&type2);
  auto cell_to_input_weights = model->addOperand(&type3);
  auto cell_to_forget_weights = model->addOperand(&type3);
  auto cell_to_output_weights = model->addOperand(&type3);
  auto input_gate_bias = model->addOperand(&type4);
  auto forget_gate_bias = model->addOperand(&type4);
  auto cell_gate_bias = model->addOperand(&type4);
  auto output_gate_bias = model->addOperand(&type4);
  auto projection_weights = model->addOperand(&type5);
  auto projection_bias = model->addOperand(&type3);
  auto activation_param = model->addOperand(&type6);
  auto cell_clip_param = model->addOperand(&type7);
  auto proj_clip_param = model->addOperand(&type7);
  auto scratch_buffer = model->addOperand(&type8);
  auto output_state = model->addOperand(&type9);
  auto cell_state = model->addOperand(&type10);
  auto output = model->addOperand(&type9);
  // Phase 2, operations
  model->addOperation(ANEURALNETWORKS_LSTM, {input, input_to_input_weights, input_to_forget_weights, input_to_cell_weights, input_to_output_weights, recurrent_to_intput_weights, recurrent_to_forget_weights, recurrent_to_cell_weights, recurrent_to_output_weights, cell_to_input_weights, cell_to_forget_weights, cell_to_output_weights, input_gate_bias, forget_gate_bias, cell_gate_bias, output_gate_bias, projection_weights, projection_bias, activation_param, cell_clip_param, proj_clip_param}, {output, scratch_buffer, output_state, cell_state});
  // Phase 3, inputs and outputs
  model->setInputsAndOutputs(
    {input, input_to_input_weights, input_to_forget_weights, input_to_cell_weights, input_to_output_weights, recurrent_to_intput_weights, recurrent_to_forget_weights, recurrent_to_cell_weights, recurrent_to_output_weights, cell_to_input_weights, cell_to_forget_weights, cell_to_output_weights, input_gate_bias, forget_gate_bias, cell_gate_bias, output_gate_bias, projection_weights, projection_bias, activation_param, cell_clip_param, proj_clip_param},
    {output, scratch_buffer, output_state, cell_state});
  assert(model->isValid());
}

bool is_ignored(int i) {
  static std::set<int> ignore = {0, 1, 2};
  return ignore.find(i) != ignore.end();
}