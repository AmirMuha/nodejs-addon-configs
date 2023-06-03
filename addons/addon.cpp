#include <iostream>
#include <napi/napi.h>

Napi::Value HelloWorld(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    // C++ function implementation
    return Napi::Number::New(env, 1200);
}

Napi::Object Init(Napi::Env env, Napi::Object exports) {
    exports.Set("HelloWorld", Napi::Function::New(env, HelloWorld));
    return exports;
}

NODE_API_MODULE(addon, Init)
