/*
	TextureManager.h
	�e�N�X�`���Ǘ��N���X
	@author Ishibashi Ryuto
	@date
	2018/09/02 ���ō쐬
*/
#pragma once
// �V�X�e���w�b�_�C���N���[�h
#include <memory>
#include <map>

// ����w�b�_�C���N���[�h
#include "Texture.h"

// �N���X�g�p�錾
class Device;

class TextureManager
{
public:
	~TextureManager();

	/// @fn static GetInstance
	/// �V���O���g���C���X�^���X���擾����
	/// @retval �e�N�X�`���}�l�[�W���̃C���X�^���X
	static TextureManager& GetInstance()
	{
		static TextureManager inst;
		return inst;
	}

	/// @fn Regist
	/// �e�N�X�`���f�[�^���}�l�[�W���ɓo�^���A�Ǘ��n���h����Ԃ�
	/// @param[in] texture : �e�N�X�`���f�[�^
	/// @retval		�e�N�X�`���̃n���h��
	int Regist(std::shared_ptr<Texture> texture);

	/// @fn Erase
	/// �w�肵���n���h���̃e�N�X�`�����폜����
	/// @param[in] int �e�N�X�`���n���h��
	void Erase(int textureHandle);

	/// @fn GetTexture
	/// �e�N�X�`���f�[�^���擾����
	/// @param[in] textureHandle : �e�N�X�`���n���h��
	/// @retval �e�N�X�`���f�[�^
	std::shared_ptr<Texture> GetTexture(int textureHandle) const;

	/// @fn IsExist
	/// �ΏۂƂ����n���h���̐悪���݂��邩�m�F����
	/// @param[in] handle �e�N�X�`���n���h��
	/// @retval ���݂���: true
	/// @retval ���݂��Ȃ�: false
	bool IsExist(int handle) const;


	/// @brief �k���e�N�X�`�����쐬����
	void CreateWhiteAndBlackTexture(std::shared_ptr<Device> device);

	static const int WHITE_TEXTURE = -1;
	static const int BLACK_TEXTURE = -2;
	
private:
	TextureManager();
	TextureManager(const TextureManager&) {}
	void operator=(const TextureManager&) {}

	std::map<int, std::shared_ptr<Texture>> mData;
	int mNextTextureHandle;

	/// @fn UpdateNowTextureHandle
	/// ���̃e�N�X�`���n���h����T�����A�X�V����
	void UpdateNextTextureHandle();


	static const int DATA_SIGNATURE_SHIFT_NUM = 24;
	static const int TEXTURE_SIGNATURE = 0x10 << DATA_SIGNATURE_SHIFT_NUM;
};
