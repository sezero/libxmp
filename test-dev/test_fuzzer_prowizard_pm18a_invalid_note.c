#include "test.h"

/* This input caused an out-of-bounds read in the Promizer 1.8a
 * depacker due to a missing sanity check on note reference values.
 */

TEST(test_fuzzer_prowizard_pm18a_invalid_note)
{
	xmp_context opaque;
	int ret;

	opaque = xmp_create_context();
	ret = xmp_load_module(opaque, "data/f/prowizard_pm18a_invalid_note");
	fail_unless(ret == -XMP_ERROR_LOAD, "module load");

	xmp_free_context(opaque);
}
END_TEST
