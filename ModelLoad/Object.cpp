#include "Object.h"

void Object::load(const char *path)
{
	Assimp::Importer importer;

	const aiScene *scene = importer.ReadFile(path, aiProcess_Triangulate | aiProcess_GenNormals | aiProcess_FlipUVs);

	if (!scene)
	{
		cerr << "Failed to load model!" << endl;
		exit(-2);
	}

	nVertices = 0;
	nTriangles = 0;

	unsigned nMeshes = scene->mNumMeshes;

	for (unsigned i = 0; i < nMeshes; ++i)
	{
		aiMesh *mesh = scene->mMeshes[i];

		//只是用来输出提示每个object总共有多多少点多少面
		nVertices += mesh->mNumVertices;
		nTriangles += mesh->mNumFaces;

		this->meshs.push_back(Mesh());
		vector<Vertex> &vertices = this->meshs.back().vertices;
		vector<GLuint> &indices = this->meshs.back().indices;

		//这里是为了vector提前reserve来提高性能用的
		unsigned mnVertices = mesh->mNumVertices;
		unsigned mnTriangles = mesh->mNumFaces;

		vertices.reserve(mnVertices);
		indices.reserve(mnTriangles);

		for (unsigned j = 0; j < mnVertices; ++j)
		{
			aiVector3D v = mesh->mVertices[j];
			aiVector3D n = mesh->mNormals[j];
			aiVector2D uv(0, 0);
			if (mesh->HasTextureCoords(0))
			{
				uv.x = mesh->mTextureCoords[0][j].x;
				uv.y = mesh->mTextureCoords[0][j].y;
			}

			vertices.push_back(Vertex(v.x, v.y, v.z, n.x, n.y, n.z, uv.x, uv.y));
		}

		unsigned mnFaces = mesh->mNumFaces;
		for (unsigned j = 0; j < mnFaces; ++j)
		{
			aiFace face = mesh->mFaces[j];
			indices.push_back(face.mIndices[0]);
			indices.push_back(face.mIndices[1]);
			indices.push_back(face.mIndices[2]);
		}
	}
}

void Object::bindBuffer()
{
	int cnt = this->meshs.size();

	for (int i = 0; i < cnt; ++i)
	{
		this->meshs[i].bindBuffer();
	}
}

void Object::render()
{
	int cnt = this->meshs.size();
	for (int i = 0; i < cnt; ++i)
	{
		this->meshs[i].render();
	}
}