#include <windows.h>

typedef struct _Chunk_Header
{
	DWORD chunkID;
	DWORD chunkSize;
} CHUNKHEADER;

typedef struct _DATA_Subchunk
{
	BYTE *sampleData;
} DATASUBCHUNK;

typedef struct _RIFF_Chunk
{
	CHUNKHEADER    riffHeader;
	DWORD          waveFormat;
	CHUNKHEADER    formatHeader;
	PCMWAVEFORMAT  formatSubchunk;
	CHUNKHEADER    dataHeader;
	DATASUBCHUNK   dataSubchunk;
} RIFFCHUNK;

/* function prototype */
RIFFCHUNK* ReadWaveFile( char *filename );
int WriteWaveFile( char *filename, RIFFCHUNK *rc );
int WritePCMSamples(const char* filename, DWORD nSamplesPerSec, WORD nBitsPerSample, WORD nChannels, long nSampleDataSize, BYTE* sampleData);
