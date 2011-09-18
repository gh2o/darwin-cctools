/* Used if LLVM support is not enabled. */

#include <stdlib.h>
#include <stdint.h>
#include <mach/mach_types.h>

#include "lto_file.h"

namespace lto
{
	const char *version () { return NULL; }
	
	const char *archName (
		const uint8_t *fileContent,
		uint64_t fileLength
	) { return NULL; }

	ld::relocatable::File* parse (
		const uint8_t* fileContent,
		uint64_t fileLength,
		const char* path,
		time_t modTime,
		uint32_t ordinal,
		cpu_type_t architecture,
		cpu_subtype_t subarch,
		bool logAllFiles
	) { return NULL; };

	bool libLTOisLoaded () { return false; }

	bool optimize (
		const std::vector<const ld::Atom*>& allAtoms,
		ld::Internal& state,
		uint32_t nextInputOrdinal,
		const OptimizeOptions& options,
		ld::File::AtomHandler& handler,
		std::vector<const ld::Atom*>& newAtoms,
		std::vector<const char*>& additionalUndefines
	) { return false; }
	
	bool isObjectFile (
		const uint8_t* fileContent,
		uint64_t fileLength,
		cpu_type_t architecture,
		cpu_subtype_t subarch
	) { return false; }
}
