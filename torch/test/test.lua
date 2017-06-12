require 'ar'
require 'cutorch'
torch.setdefaulttensortype('torch.FloatTensor')
x=torch.ones(1,5):cuda()
ar.init()
ar.allreduce(x,5)
print(x)
ar.finalize()

