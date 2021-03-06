#include "caffe2/operators/experimental/c10/schemas/expand_dims.h"
#include <c10/core/dispatch/OpSchemaRegistration.h>
#include "caffe2/core/operator_c10wrapper.h"

using caffe2::CPUContext;

C10_DEFINE_OP_SCHEMA(caffe2::ops::ExpandDims);

namespace {
struct DimsParameter final {
  using type = std::vector<int>;
  static std::vector<int> parse(const caffe2::ArgumentHelper& helper) {
    return helper.GetRepeatedArgument<int>("dims");
  }
};
} // namespace

namespace caffe2 {
REGISTER_C10_OPERATOR_FOR_CAFFE2_DISPATCH_WITH_PARAMETERS(
    ops::ExpandDims,
    ops::ExpandDims::State,
    C10ExpandDims_DontUseThisOpYet,
    DimsParameter)
}
