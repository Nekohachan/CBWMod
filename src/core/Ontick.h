#pragma once
#include "ll/api/coro/CoroTask.h"
#include <atomic>

namespace cb {

ll::coro::CoroTask<> OnTick(std::atomic<bool>& shouldStop);

} // namespace cb