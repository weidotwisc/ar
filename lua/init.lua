----------------------------------------------------------------------
-- ar - a package that provides simple api for ar
----------------------------------------------------------------------

-- local os = require 'os'
-- local io = require 'io'
require 'torch'

ar = {}

--------------------------------------------------------------------------------
-- load all functions from lnexus
--------------------------------------------------------------------------------
local _lar = require 'liblar'
-- import nexus packages directly
-- for k,v in pairs(_lnexus) do
--   nexus[k] = v
-- end

--------------------------------------------------------------------------------
-- create ar functions
--------------------------------------------------------------------------------
function ar.init()
  _lar.init()
end

function ar.finalize()
   _lar.finalize()
end

function ar.get_rank()
  return _lar.get_rank()
end

function ar.allreduce(t, cnt)
   _lar.allreduce(t:storage(), cnt)
end

return ar

