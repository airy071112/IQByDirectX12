#include <iostream>
#include "PMDLoader.h"


PMDLoader::PMDLoader()
{
}


PMDLoader::~PMDLoader()
{
}

std::shared_ptr<PMDLoader> PMDLoader::Create()
{
	return std::shared_ptr<PMDLoader>(new PMDLoader());
}

std::shared_ptr<PMDModelData> PMDLoader::LoadModel(const std::string & filePath)
{
	unsigned int vertexCount;
	std::vector<PMDVertex> vertex;
	unsigned int indexCount;
	std::vector<unsigned short> index;
	unsigned int materialCount;
	std::vector<PMDMaterial> materials;

	PMDHeader pmdHeader;

	// ファイルを開く
	FILE *fp;
	fopen_s(&fp, filePath.c_str(), "rb");

	if (fp == nullptr)
	{
		return nullptr;
	}

	// ファイルフォーマットの確認
	{
		char pmdSignature[3];
		fread(pmdSignature, sizeof(pmdSignature), 1, fp);

		if (strcmp(pmdSignature, "Pmd") != 0)
		{
			std::cout << "This file is not pmd.\n Please load \".pmd\" file." << std::endl;
			fclose(fp);
			return nullptr;
		}
	}

	// ヘッダデータ読み込み
	fread(&pmdHeader, sizeof(pmdHeader), 1, fp);

	// 頂点情報の読み込み
	fread(&vertexCount, sizeof(int), 1, fp);
	vertex.resize(vertexCount);
	fread(vertex.data(), sizeof(PMDVertex), vertex.size(), fp);

	// 頂点インデックス情報読み込み
	fread(&indexCount, sizeof(int), 1, fp);
	index.resize(indexCount);
	fread(index.data(), sizeof(int), index.size(), fp);

	// マテリアルパラメータ読み込み
	fread(&materialCount, sizeof(int), 1, fp);
	materials.resize(materialCount);
	fread(materials.data(), sizeof(PMDMaterial), materials.size(), fp);

	fclose(fp);

	return PMDModelData::Create(vertex, index, materials);
}
