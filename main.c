#include <stdio.h>
#include "wave.h"

//두번째 경우에 사용하는
#include <math.h>
#define NUM_SCALE 120
#define PI 3.1415926535897

int main(void)
{
	////1. RIFF 파일 불러와서 RIFF, 포맷, 데이터 청크만 뽑아와 새로 저장하는 코드
	//RIFFCHUNK *rc;
	//char     *inputFile="sample_PCM_in1.wav";
	////char     *inputFile="sample-Alaw.wav";
	//char     *outputFile="sample_PCM_out.wav";

	//if( (rc=ReadWaveFile( inputFile )) != NULL )
	//{
	//	printf( "[%s] reading success \n", inputFile );
	//	if( WriteWaveFile( outputFile, rc ) == 0 )
	//	{
	//		printf( "[%s] writing success \n", outputFile );
	//	}
	//	free( rc->dataSubchunk.sampleData );
	//	free(rc);
	//}
	//else
	//{
	//	printf( "[%s] reading error \n", inputFile );
	//}

	//return 0;


	//2. 두번째
	//char* filename;
	//const double baseFrequency = 220.0;
	//int    scaleIndex[NUM_SCALE] =
	//{ 3, 5, 7, 8, 10, 12, 14, 15 };
	//double freq[NUM_SCALE];
	//int whatTone = 0;
	//
	//DWORD  nSamplesPerSec = 8000; // 8KHz sampling
	//WORD   nBitsPerSample = 16; // 8 or 16bits
	//WORD   nChannels = 2; // mono(1) or stereo(2)
	//double fSamplesInterval = 1.0 / nSamplesPerSec; // 125μs for 8KHz
	//double fPlayTime = 1.0; // play time of each tone
	//long   nSampleDataSize; // total size of samples
	//BYTE* sampleData;
	//double sampleLoc; // sample location to be processed
	//long   index;
	//int    result;

	//// 주파수에 따른 음계 생성
	//for (index = 0; index < NUM_SCALE; index++)
	//	freq[index] = baseFrequency * pow(2.0, scaleIndex[index] / 12.0);

	//nSampleDataSize = (long)(fPlayTime *
	//	nSamplesPerSec * nChannels *
	//	nBitsPerSample / 8);
	//sampleData = (BYTE*)malloc(sizeof(BYTE) *
	//	nSampleDataSize*NUM_SCALE);
	//
	//printf("생성할 Tone의 비트 수 선택\n1 : 8bit\n2 : 16bit\n> ");
	//scanf(" %d", &whatTone);
	//if (whatTone == 1) nBitsPerSample = 8; else nBitsPerSample = 16;
	//printf("생성할 Tone의 종류 선택\n1 : pure\n2 : complex\n> ");
	//scanf(" %d", &whatTone);
	////예외처리 하지않음

	//sampleLoc = 0.0;
	//for (int tt = 0; tt < NUM_SCALE; tt++) {
	//	for (index = nSampleDataSize*tt; index < nSampleDataSize*(tt+1); index++)
	//	{
	//		if (nBitsPerSample == 8)
	//		{
	//			double value = 0;
	//			BYTE   v;
	//			
	//			switch (whatTone) {
	//			case(1):
	//				// Pure tone
	//				filename = "synthesis_pure_8bit.wav";
	//				value = sin(2.0 * PI * freq[tt] * sampleLoc);
	//				break;
	//			case(2):
	//				// Complex tone
	//				filename = "synthesis_complex_8bit.wav";
	//				value = 0.6 * sin(2.0 * PI * freq[tt] * sampleLoc);
	//				value += 0.2 * sin(2.0 * 2 * PI * freq[tt] * sampleLoc);
	//				value += 0.1 * sin(2.0 * 3 * PI * freq[tt] * sampleLoc);
	//				break;
	//			default:
	//				break;
	//			}
	//			v = sampleData[index] =
	//				(BYTE)(128.0 + 100.0 * value + 0.5);
	//			if (nChannels == 2)
	//				sampleData[++index] = v;
	//		}
	//		else if (nBitsPerSample == 16)
	//		{
	//			union _sample {
	//				BYTE channel[2];
	//				short value;
	//			} sample;
	//			double value = 0;
	//			BYTE low, high;

	//			switch (whatTone) {
	//			case(1):
	//				// Pure tone
	//				filename = "synthesis_pure_16bit.wav";
	//				value = sin(2.0 * PI * freq[tt] * sampleLoc);
	//				break;
	//			case(2):
	//				// Complex tone
	//				filename = "synthesis_complex_16bit.wav";
	//				value = 0.6 * sin(2.0 * PI * freq[tt] * sampleLoc);
	//				value += 0.2 * sin(2.0 * 2 * PI * freq[tt] * sampleLoc);
	//				value += 0.1 * sin(2.0 * 3 * PI * freq[tt] * sampleLoc);
	//				break;
	//			default:
	//				break;
	//			}
	//			sample.value = (short)(30000.0 * value + 0.5);
	//			low = sampleData[index] = sample.channel[0];
	//			high = sampleData[++index] = sample.channel[1];
	//			if (nChannels == 2)
	//			{
	//				sampleData[++index] = low;
	//				sampleData[++index] = high;
	//			}
	//		}
	//		sampleLoc += fSamplesInterval;
	//	} // end of for( index
	//}

	//result = WritePCMSamples(filename, nSamplesPerSec,
	//	nBitsPerSample, nChannels,
	//	nSampleDataSize*NUM_SCALE, sampleData);
	//if (result == 0)
 //		printf("Success \n");

	//free(sampleData);

	//return 0;

	//세번째
	char* filename;
	const double baseFrequency = 220.0;
	int    scaleIndex[NUM_SCALE] =
	{ 7,7,7,7,7,7, 5,5, 3,3,3,3, 5,5,5,5, 7,7,7,-200, 7,7,7,-200, 7,7,7,7,7,7,-200,-200,
		5,5,5,-200, 5,5,5,-200, 5,5,5,5,5,5,-200,-200, 7,7,7,7, 10,10,10,-200, 10,10,10,10,10,10,-200,-200,
		7,7,7,7,7,7, 5,5, 3,3,3,3, 5,5,5,5, 7,7,7,-200, 7,7,7,-200, 7,7,7,7,7,7,-200,-200,
		5,5,5,-200, 5,5,5,-200, 7,7,7,-200, 5,5,5,-200, 3,3,3,3,3,3,-200,-200 };
	double freq[NUM_SCALE];
	int whatTone = 0;
	int stereomode = 0;

	DWORD  nSamplesPerSec = 8000; // 8KHz sampling
	WORD   nBitsPerSample = 16; // 8 or 16bits
	WORD   nChannels = 2; // mono(1) or stereo(2)
	double fSamplesInterval = 1.0 / nSamplesPerSec; // 125μs for 8KHz
	double fPlayTime = 0.05; // play time of each tone
	long   nSampleDataSize; // total size of samples
	BYTE* sampleData;
	double sampleLoc; // sample location to be processed
	long   index;
	int    result;

	// 주파수에 따른 음계 생성
	for (index = 0; index < NUM_SCALE; index++)
		freq[index] = baseFrequency * pow(2.0, scaleIndex[index] / 12.0);

	nSampleDataSize = (long)(fPlayTime *
		nSamplesPerSec * nChannels *
		nBitsPerSample / 8);
	sampleData = (BYTE*)malloc(sizeof(BYTE) *
		nSampleDataSize*NUM_SCALE);

	printf("생성할 Tone의 표본화율 입력(기본 : 8000)\n> ");
	scanf(" %d", &nSamplesPerSec);
	printf("생성할 Tone의 표본 당 비트 수 선택\n1 : 8bit\n2 : 16bit\n> ");
	scanf(" %d", &whatTone);
	if (whatTone == 1) nBitsPerSample = 8; else nBitsPerSample = 16;
	printf("생성할 Tone의 채널개수 선택\n1 : mono\n2 : stereo\n> ");
	scanf(" %d", &nChannels);
	if (nChannels == 2) {
		printf("stereo 모드 선택\n0 : none\n1 : 진폭변화\n2 : 시작시간 변화\n> ");
		scanf(" %d", &stereomode);
	}
	printf("고조주파수 입힐 갯수 입력하세요\n0 : none\n1 : 1개\n2 : 2개\n3 : 3개\n> ");
	scanf(" %d", &whatTone);
	//예외처리 하지않음

	if (whatTone == 1 && nChannels == 1) fPlayTime /= 2;
	sampleLoc = 0.0;
	for (int tt = 0; tt < NUM_SCALE; tt++) {
		for (index = nSampleDataSize*tt; index < nSampleDataSize*(tt+1); index++)
		{
			if (nBitsPerSample == 8)
			{
				double value = 0;
				BYTE   v;
	
				switch (whatTone) {
				case(0):
					// Pure tone
					filename = "synthesis_pure_8bit_mono.wav";
					value = sin(2.0 * PI * freq[tt] * sampleLoc);
					break;
				case(3):
					// Complex tone1
					value += 0.1 * sin(2.0 * 3 * PI * freq[tt] * sampleLoc);
				case(2):
					value += 0.2 * sin(2.0 * 2 * PI * freq[tt] * sampleLoc);
					// Complex tone2
				case(1):
					filename = "synthesis_complex_8bit_mono.wav";
					value += 0.6 * sin(2.0 * PI * freq[tt] * sampleLoc);
					// Complex tone3
					break;
				default:
					break;
				}

				v = sampleData[index] =
					(BYTE)(128.0 + 100.0 * value + 0.5);
				if (nChannels == 2) {
					if (stereomode == 1)
						sampleData[++index] = (BYTE)(128.0 + 20.0 * value + 0.5);
					else if (stereomode == 0)
						sampleData[++index] = (BYTE)(128.0 + 100.0 * value + 0.5);
					else if (stereomode == 2 && index + 4001 < nSampleDataSize * NUM_SCALE)
						sampleData[++index + 4000] = v;

					if (filename == "synthesis_pure_8bit_mono.wav")
						filename = "synthesis_pure_8bit_stereo.wav";
					else if (filename == "synthesis_complex_8bit_mono.wav")
						filename = "synthesis_complex_8bit_stereo.wav";
					
				}
			}
			else if (nBitsPerSample == 16)
			{
				union _sample {
					BYTE channel[2];
					short value;
				} sample;
				static double value = 0;
				BYTE low, high;

				switch (whatTone) {
				case(0):
					// Pure tone
					filename = "synthesis_pure_16bit_mono.wav";
					value = sin(2.0 * PI * freq[tt] * sampleLoc);
					break;
				case(3):
					// Complex tone1
					value += 0.1 * sin(2.0 * 3 * PI * freq[tt] * sampleLoc);
				case(2):
					value += 0.2 * sin(2.0 * 2 * PI * freq[tt] * sampleLoc);
					// Complex tone2
				case(1):
					filename = "synthesis_complex_16bit_mono.wav";
					value += 0.6 * sin(2.0 * PI * freq[tt] * sampleLoc);
					// Complex tone3
					break;
				default:
					break;
				}
				sample.value = (short)(30000.0 * value + 0.5);
				low = sampleData[index] = sample.channel[0];
				high = sampleData[++index] = sample.channel[1];
				if (nChannels == 2)
				{
					if (stereomode == 1) {
						sample.value = (short)(20003.0 * value + 0.5);
						sampleData[++index] = sample.channel[0];
						sampleData[++index] = sample.channel[1];
					}
					else if (stereomode == 0) {
						sampleData[++index] = low;
						sampleData[++index] = high;
					}
					else if (stereomode == 2 && index + 4001 < nSampleDataSize * NUM_SCALE) {
						sampleData[++index + 4000] = low;
						sampleData[++index + 4000] = high;
					}
		

					if (filename == "synthesis_pure_16bit_mono.wav")
						filename = "synthesis_pure_16bit_stereo.wav";
					else if (filename == "synthesis_complex_16bit_mono.wav")
						filename = "synthesis_complex_16bit_stereo.wav";
				}
			}
			sampleLoc += fSamplesInterval;
		} // end of for( index
	}

	result = WritePCMSamples(filename, nSamplesPerSec,
		nBitsPerSample, nChannels,
		nSampleDataSize*NUM_SCALE, sampleData);
	if (result == 0)
 		printf("Success \n");

	free(sampleData);

	return 0;
}