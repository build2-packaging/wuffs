#include <wuffs/wuffs.h>

#include <string>

#undef NDEBUG
#include <cassert>

class callbacks : public wuffs_aux::DecodeJsonCallbacks
{
public:
  std::string
  AppendNull () override
  {
    return std::string ();
  }

  std::string
  AppendBool (bool) override
  {
    return std::string ();
  }

  std::string
  AppendF64 (double) override
  {
    return std::string ();
  }

  std::string
  AppendI64 (int64_t) override
  {
    return std::string ();
  }

  std::string
  AppendTextString (std::string&&) override
  {
    return std::string ();
  }

  std::string
  Push (uint32_t) override
  {
    return std::string ();
  }

  std::string
  Pop (uint32_t) override
  {
    return std::string ();
  }
};

int
main ()
{
  callbacks cb;
  const char json[] = "true";
  wuffs_aux::sync_io::MemoryInput in (json, sizeof (json) - 1);
  wuffs_aux::DecodeJsonResult r (wuffs_aux::DecodeJson (cb, in));
  assert (r.error_message.empty ());
  return 0;
}
