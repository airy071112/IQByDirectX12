/*
	IndexBuffer.h
	�C���f�b�N�X�����i�[����o�b�t�@
	@author Ishibashi Ryuto
	@param history
	2018/08/28		���ō쐬
*/
#pragma once
// �V�X�e���w�b�_�C���N���[�h
#include <memory>
#include <wrl.h>
#include <d3d12.h>

// ����w�b�_�C���N���[�h

// �N���X�O���錾
using Microsoft::WRL::ComPtr;

class IndexBuffer
{
public:
	~IndexBuffer();

	/// @fn Create
	/// ���_�C���f�b�N�X�o�b�t�@�̐���
	/// @note IndexBuffer�N���X�͂��̃��\�b�h�ɂ���Ă̂ݐ����\
	/// @param[in] device: ID3D12Device
	/// @param[in] pIndexResource: �C���f�b�N�X���\�[�X�̃|�C���^
	/// @param[in] indexCount: �C���f�b�N�X�̐�
	/// @param[in] indexSize: �C���f�b�N�X1������̃T�C�Y(sizeof�Ŏ擾)
	/// @retval ��������: VertexBuffer��shared_ptr, �������s: nullptr
	static std::shared_ptr<IndexBuffer> Create(ComPtr<ID3D12Device> device, void* pIndexResource, size_t indexCount, size_t indexSize);
private:
	IndexBuffer();
	ComPtr<ID3D12Resource> mIndexBuffer;
	D3D12_INDEX_BUFFER_VIEW mIndexBufferView;
};
