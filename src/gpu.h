// Tencent is pleased to support the open source community by making ncnn available.
//
// Copyright (C) 2018 THL A29 Limited, a Tencent company. All rights reserved.
//
// Licensed under the BSD 3-Clause License (the "License"); you may not use this file except
// in compliance with the License. You may obtain a copy of the License at
//
// https://opensource.org/licenses/BSD-3-Clause
//
// Unless required by applicable law or agreed to in writing, software distributed
// under the License is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
// CONDITIONS OF ANY KIND, either express or implied. See the License for the
// specific language governing permissions and limitations under the License.

#ifndef NCNN_GPU_H
#define NCNN_GPU_H

// opencl
#include <CL/cl.h>

namespace ncnn {

class Extractor;
class Queue
{
public:
    ~Queue();

    // NOTE opencl
    operator cl_command_queue()
    {
        return clqueue;
    }

private:
    friend class Extractor;
    Queue();

    cl_command_queue clqueue;
};

int init_gpu_device();

cl_device_id get_gpu_device();

cl_context get_gpu_context();

int compile_gpu_kernel();

cl_kernel get_gpu_kernel(const char* name);

} // namespace ncnn

#endif // NCNN_GPU_H
