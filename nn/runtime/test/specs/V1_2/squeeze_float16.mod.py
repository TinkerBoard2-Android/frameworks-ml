#
# Copyright (C) 2020 The Android Open Source Project
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#      http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
#

model = Model()
i1 = Input("input", "TENSOR_FLOAT16", "{4, 1, 1, 2}")
squeezeDims = Parameter("squeezeDims", "TENSOR_INT32", "{2}", [1, 2])
output = Output("output", "TENSOR_FLOAT16", "{4, 2}")

model = model.Operation("SQUEEZE", i1, squeezeDims).To(output)

# Example 1. Input in operand 0,
input0 = {i1: # input 0
          [1.4, 2.3, 3.2, 4.1, 5.4, 6.3, 7.2, 8.1]}

output0 = {output: # output 0
           [1.4, 2.3, 3.2, 4.1, 5.4, 6.3, 7.2, 8.1]}

# Instantiate an example
Example((input0, output0))

# Test with omitted squeeze dims
squeezeDims = Parameter("squeezeDims", ["TENSOR_INT32", [0]], value=None)
Model("omitted").Operation("SQUEEZE", i1, squeezeDims).To(output)
Example((input0, output0))
