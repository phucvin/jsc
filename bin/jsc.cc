#include "lib.cc"

void recursion_fib(const FunctionCallbackInfo<Value>& args) {
  Isolate* isolate = args.GetIsolate();
  Local<Value> recursion_i = args[0];

tail_recurse_0:

  ;

  Local<Value> sym_bin_exp_8 = ((toNumber(recursion_i) <= 1) ? True(isolate) : False(isolate));
  bool sym_if_test_3 = toBoolean(sym_bin_exp_8);
  if (sym_if_test_3) {
    args.GetReturnValue().Set(recursion_i);
    return;
  }

  Local<Value> sym_arg_17 = genericMinus(isolate, recursion_i, Number::New(isolate, 1));
  Local<Value> sym_args_24[] = { sym_arg_17 };
  Local<Value> sym_lhs_16 = FunctionTemplate::New(isolate, recursion_fib)->GetFunction()->Call(FunctionTemplate::New(isolate, recursion_fib)->GetFunction(), 1, sym_args_24);

  Local<Value> sym_arg_29 = genericMinus(isolate, recursion_i, Number::New(isolate, 2));
  Local<Value> sym_args_36[] = { sym_arg_29 };
  Local<Value> sym_rhs_28 = FunctionTemplate::New(isolate, recursion_fib)->GetFunction()->Call(FunctionTemplate::New(isolate, recursion_fib)->GetFunction(), 1, sym_args_36);

  Local<Value> sym_ret_15 = genericPlus(isolate, sym_lhs_16, sym_rhs_28);
  args.GetReturnValue().Set(sym_ret_15);
  return;
}

void jsc_main(const FunctionCallbackInfo<Value>& args) {
  Isolate* isolate = args.GetIsolate();

tail_recurse_1:

  ;
  Local<Value> sym_args_47[] = { Number::New(isolate, 20) };
  Local<Value> sym_arg_44 = FunctionTemplate::New(isolate, recursion_fib)->GetFunction()->Call(FunctionTemplate::New(isolate, recursion_fib)->GetFunction(), 1, sym_args_47);

  Local<Value> sym_args_51[] = { sym_arg_44 };
  Local<Value> sym_parent_53 = isolate->GetCurrentContext()->Global()->Get(String::NewFromUtf8(isolate, "console"));
  Local<Value> sym_fn_52 = Local<Object>::Cast(sym_parent_53)->Get(String::NewFromUtf8(isolate, "log"));
  Local<Value> sym_block_43 = Local<Function>::Cast(sym_fn_52)->Call(Local<Function>::Cast(sym_fn_52), 1, sym_args_51);

}

void Init(Local<Object> exports) {
  NODE_SET_METHOD(exports, "jsc_main", jsc_main);
}

NODE_MODULE(NODE_GYP_MODULE_NAME, Init)
