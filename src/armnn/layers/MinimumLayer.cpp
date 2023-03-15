//
// Copyright © 2017-2023 Arm Ltd and Contributors. All rights reserved.
// SPDX-License-Identifier: MIT
//

#include "MinimumLayer.hpp"

#include "LayerCloneBase.hpp"

#include <armnn/TypesUtils.hpp>
#include <armnn/backends/WorkloadData.hpp>
#include <armnn/backends/WorkloadFactory.hpp>

namespace armnn
{

MinimumLayer::MinimumLayer(const char* name)
    : ElementwiseBaseLayer(2, 1, LayerType::Minimum, name)
{
}

std::unique_ptr<IWorkload> MinimumLayer::CreateWorkload(const IWorkloadFactory& factory) const
{
    MinimumQueueDescriptor descriptor;
    SetAdditionalInfo(descriptor);

    return factory.CreateWorkload(LayerType::Minimum, descriptor, PrepInfoAndDesc(descriptor));
}

ARMNN_NO_DEPRECATE_WARN_BEGIN
MinimumLayer* MinimumLayer::Clone(Graph& graph) const
{
    return CloneBase<MinimumLayer>(graph, GetName());
}
ARMNN_NO_DEPRECATE_WARN_END

void MinimumLayer::ExecuteStrategy(IStrategy& strategy) const
{
    strategy.ExecuteStrategy(this, GetParameters(), {}, GetName());
}

} // namespace armnn
