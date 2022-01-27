#include"tasker.h"

#undef slots
#include "torch/torch.h"
#include "torch/script.h"
#define slots Q_SLOTS

using std::cout;
using std::endl;

void tasker_libtorch::task1(){
    torch::Tensor a = torch::rand({5,7});
    cout<<a<<endl;
    cout<<a.sizes()<<endl;
}
