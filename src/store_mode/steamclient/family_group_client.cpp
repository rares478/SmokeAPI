#include <store_mode/steamclient/steamclient.hpp>

VIRTUAL(bool) FamilyGroupRunningApp(PARAMS(void* mysteryInterface)) {
    LOG_DEBUG("{}(this={}, arg={})", __func__, THIS, mysteryInterface);
    return true; 
}