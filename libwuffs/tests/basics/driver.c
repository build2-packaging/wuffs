#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <wuffs/wuffs.h>

#undef NDEBUG
#include <assert.h>

#ifndef DST_BUFFER_ARRAY_SIZE
#define DST_BUFFER_ARRAY_SIZE 1024
#endif

static uint8_t g_dst_buffer_array[DST_BUFFER_ARRAY_SIZE];

/* gzip-encoded "Hello Wuffs.\n" produced by:
 *
 *   echo "Hello Wuffs." | gzip --no-name
 */
static uint8_t g_src_array[] = {
    0x1f, 0x8b, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0xf3,
    0x48, 0xcd, 0xc9, 0xc9, 0x57, 0x08, 0x2f, 0x4d, 0x4b, 0x2b, 0xd6,
    0xe3, 0x02, 0x00, 0x3c, 0x84, 0x75, 0xbb, 0x0d, 0x00, 0x00, 0x00,
};

#define WORK_BUFFER_ARRAY_SIZE \
  WUFFS_GZIP__DECODER_WORKBUF_LEN_MAX_INCL_WORST_CASE

#if WORK_BUFFER_ARRAY_SIZE > 0
static uint8_t g_work_buffer_array[WORK_BUFFER_ARRAY_SIZE];
#else
static uint8_t g_work_buffer_array[1];
#endif

int
main (void)
{
  static const char want[] = "Hello Wuffs.\n";

  wuffs_gzip__decoder* dec = wuffs_gzip__decoder__alloc ();
  assert (dec != NULL);

  wuffs_base__io_buffer dst = wuffs_base__ptr_u8__writer (
      &g_dst_buffer_array[0], DST_BUFFER_ARRAY_SIZE);

  wuffs_base__io_buffer src = wuffs_base__ptr_u8__reader (
      &g_src_array[0], sizeof (g_src_array), true);

  wuffs_base__status status = wuffs_gzip__decoder__transform_io (
      dec,
      &dst,
      &src,
      wuffs_base__make_slice_u8 (&g_work_buffer_array[0],
                                 WORK_BUFFER_ARRAY_SIZE));
  free (dec);

  assert (wuffs_base__status__is_ok (&status));
  assert (dst.meta.wi == (sizeof (want) - 1));
  assert (memcmp (dst.data.ptr, want, sizeof (want) - 1) == 0);

  return 0;
}
