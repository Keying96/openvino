// Copyright (C) 2019 Intel Corporation
// SPDX-License-Identifier: Apache-2.0
//

#include <vector>

#include "single_layer_tests/split.hpp"
#include "common_test_utils/test_constants.hpp"

using namespace LayerTestsDefinitions;

namespace {
const std::vector<InferenceEngine::Precision> netPrecisions = {
        InferenceEngine::Precision::FP32,
        InferenceEngine::Precision::FP16
};

// TODO: Issue:  26411
INSTANTIATE_TEST_CASE_P(DISABLED_smoke_NumSplitsCheck, SplitLayerTest,
                        ::testing::Combine(
                                ::testing::Values(1),
                                ::testing::Values(0, 1),
                                ::testing::ValuesIn(netPrecisions),
                                ::testing::Values(std::vector<size_t >({30, 30})),
                                ::testing::Values(CommonTestUtils::DEVICE_GNA)),
                        SplitLayerTest::getTestCaseName);

}  // namespace