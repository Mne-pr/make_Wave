#include <stdio.h>
#include "wave.h"

RIFFCHUNK* ReadWaveFile(char *filename)
{
	FILE        *fp;
	CHUNKHEADER h;
	BYTE        *sampleData;
	RIFFCHUNK   *rc;

	fp = fopen(filename, "rb");
	if (fp == NULL)
	{
		printf("File NOT Found \n");
		return NULL;
	}

	// allocate memory for RIFF chunk
	rc = (RIFFCHUNK*)malloc(sizeof(RIFFCHUNK));
	if (rc == NULL)
	{
		printf("Error in memory allocation! \n");
		return NULL;
	}

	while (fread(&h, sizeof(CHUNKHEADER), 1, fp) != 0)
	{
		// Check RIFF Chunk ("RIFF")
		//if( h.chunkID == 0x46464952 )
		if (h.chunkID == MAKEFOURCC('R', 'I', 'F', 'F'))
		{
			rc->riffHeader = h;
			fread(&(rc->waveFormat),
				sizeof(rc->waveFormat), 1, fp);

			// check "WAVE" format
			//if (rc->waveFormat != 0x45564157)
			if (rc->waveFormat !=
				MAKEFOURCC('W', 'A', 'V', 'E'))
			{
				printf("NOT supported format \n");

				free(rc);
				return NULL;
			}
		}
		// Check FORMAT Chunk ("fmt ")
		//else if( h.chunkID == 0x20746D66 )
		else if (h.chunkID == MAKEFOURCC('f', 'm', 't', ' '))
		{
			PCMWAVEFORMAT fsc;

			rc->formatHeader = h;

			fread(&fsc, sizeof(PCMWAVEFORMAT), 1, fp);
			if (!(fsc.wf.wFormatTag == 1 &&
				(fsc.wBitsPerSample == 8 ||
				fsc.wBitsPerSample == 16)))
			{
				printf("bits per a sample: %d \n",
					fsc.wBitsPerSample);
				printf("NOT supported format \n");

				free(rc);
				return NULL;
			}
			rc->formatSubchunk = fsc;
		}
		// Check DATA Chunk ("data")
		//else if( h.chunkID == 0x61746164 )
		else if (h.chunkID == MAKEFOURCC('d', 'a', 't', 'a'))
		{
			rc->dataHeader = h;

			sampleData = (BYTE *)malloc(sizeof(BYTE)*
				h.chunkSize);
			fread(sampleData, h.chunkSize, 1, fp);
			rc->dataSubchunk.sampleData = sampleData;
		}
		else  // ignore extra chunks
		{
			//과제 1번!!
			rc->riffHeader.chunkSize -= h.chunkSize;
			//과제 1번!!
			fseek(fp, (long)h.chunkSize, SEEK_CUR);
		}
	}

	fclose(fp);

	return rc;
}


int WriteWaveFile( char *filename, RIFFCHUNK *rc )
{
	FILE        *fp;
	BYTE        *sampleData;

	fp = fopen( filename, "wb" );
	if( fp == NULL )
	{
		printf( "File open error \n" );
		return -1;
	}

	fwrite( &(rc->riffHeader),     sizeof(CHUNKHEADER), 1, fp );
	fwrite(&(rc->waveFormat),      sizeof(DWORD), 1, fp);
	fwrite( &(rc->formatHeader),   sizeof(CHUNKHEADER), 1, fp );
	fwrite(&(rc->formatSubchunk),  sizeof(PCMWAVEFORMAT), 1, fp);
	fwrite( &(rc->dataHeader),     sizeof(CHUNKHEADER), 1, fp );
	sampleData = rc->dataSubchunk.sampleData;
	fwrite( sampleData, sizeof(BYTE), rc->dataHeader.chunkSize, fp );

	fclose( fp );

	return 0;
}

//두번째 wave.c에 추거된 코드
int WritePCMSamples(char* filename, DWORD nSamplesPerSec,
	WORD nBitsPerSample, WORD nChannels,
	long nSampleDataSize, BYTE* sampleData)
{
	RIFFCHUNK rc;

	//rc.riffHeader.chunkID = 0x46464952; // "RIFF"
	rc.riffHeader.chunkID = MAKEFOURCC('R', 'I', 'F', 'F');
	rc.riffHeader.chunkSize = nSampleDataSize + 36;

	//rc.waveFormat = 0x45564157; // "WAVE"
	rc.waveFormat = MAKEFOURCC('W', 'A', 'V', 'E');

	//rc.formatHeader.chunkID = 0x20746d66;  // "fmt "
	rc.formatHeader.chunkID = MAKEFOURCC('f', 'm', 't', ' ');
	rc.formatHeader.chunkSize = 16;

	rc.formatSubchunk.wf.wFormatTag = 1;
	rc.formatSubchunk.wf.nChannels = nChannels;
	rc.formatSubchunk.wf.nSamplesPerSec = nSamplesPerSec;
	rc.formatSubchunk.wf.nAvgBytesPerSec = nSamplesPerSec *
		nChannels * nBitsPerSample / 8;
	rc.formatSubchunk.wf.nBlockAlign = nChannels *
		nBitsPerSample / 8;
	rc.formatSubchunk.wBitsPerSample = nBitsPerSample;

	//rc.dataHeader.chunkID = 0x61746164;   // "data"
	rc.dataHeader.chunkID = MAKEFOURCC('d', 'a', 't', 'a');
	rc.dataHeader.chunkSize = nSampleDataSize;

	rc.dataSubchunk.sampleData = sampleData;

	return WriteWaveFile(filename, &rc);
}