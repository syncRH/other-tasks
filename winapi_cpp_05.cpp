#include <iostream>
#include <Windows.h>
#include <tchar.h> 
#include <cstdio>
#include <string>
#include <string>
#include <strsafe.h>
#include <vector>

std::string attributeFile(WIN32_FIND_DATA file)
{
	std::string buffer = "\nAttributesFile: ";
	/*
	 *  FILE_ATTRIBUTE_ARCHIVE
		FILE_ATTRIBUTE_COMPRESSED
		FILE_ATTRIBUTE_DEVICE
		FILE_ATTRIBUTE_DIRECTORY
		FILE_ATTRIBUTE_ENCRYPTED
		FILE_ATTRIBUTE_HIDDEN
		FILE_ATTRIBUTE_INTEGRITY_STREAM
		FILE_ATTRIBUTE_NORMAL
		FILE_ATTRIBUTE_NOT_CONTENT_INDEXED
		FILE_ATTRIBUTE_NO_SCRUB_DATA
		FILE_ATTRIBUTE_OFFLINE
		FILE_ATTRIBUTE_READONLY
		FILE_ATTRIBUTE_RECALL_ON_DATA_ACCESS
		FILE_ATTRIBUTE_RECALL_ON_OPEN
		FILE_ATTRIBUTE_REPARSE_POINT
		FILE_ATTRIBUTE_SPARSE_FILE
		FILE_ATTRIBUTE_SYSTEM
		FILE_ATTRIBUTE_TEMPORARY
		FILE_ATTRIBUTE_VIRTUAL
	 */
	if (file.dwFileAttributes & FILE_ATTRIBUTE_ARCHIVE)
	{
		buffer += " :ARCHIVE: ";
	}
	if (file.dwFileAttributes & FILE_ATTRIBUTE_COMPRESSED)
	{
		buffer += " :COMPRESSED: ";
	}
	if (file.dwFileAttributes & FILE_ATTRIBUTE_DEVICE)
	{
		buffer += " :DEVICE: ";
	}
	if (file.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)
	{
		buffer += " :DIRECTORY: ";
	}	if (file.dwFileAttributes & FILE_ATTRIBUTE_ENCRYPTED)
	{
		buffer += " :ENCRYPTED: ";
	}
	if (file.dwFileAttributes & FILE_ATTRIBUTE_HIDDEN)
	{
		buffer += " :HIDDEN: ";
	}
	if (file.dwFileAttributes & FILE_ATTRIBUTE_INTEGRITY_STREAM)
	{
		buffer += " :INTEGRITY_STREAM: ";
	}
	if (file.dwFileAttributes & FILE_ATTRIBUTE_NORMAL)
	{
		buffer += " :NORMAL: ";
	}
	if (file.dwFileAttributes & FILE_ATTRIBUTE_NOT_CONTENT_INDEXED)
	{
		buffer += " :NOT_CONTENT_INDEXED: ";
	}
	if (file.dwFileAttributes & FILE_ATTRIBUTE_NO_SCRUB_DATA)
	{
		buffer += " :NO_SCRUB_DATA: ";
	}
	if (file.dwFileAttributes & FILE_ATTRIBUTE_OFFLINE)
	{
		buffer += " :OFFLINE: ";
	}
	if (file.dwFileAttributes & FILE_ATTRIBUTE_READONLY)
	{
		buffer += " :READONLY: ";
	}
	if (file.dwFileAttributes & FILE_ATTRIBUTE_RECALL_ON_DATA_ACCESS)
	{
		buffer += " :RECALL_ON_DATA_ACCESS: ";
	}
	if (file.dwFileAttributes & FILE_ATTRIBUTE_RECALL_ON_OPEN)
	{
		buffer += " :RECALL_ON_OPEN: ";
	}
	if (file.dwFileAttributes & FILE_ATTRIBUTE_REPARSE_POINT)
	{
		buffer += " :REPARSE_POINT: ";
	}
	if (file.dwFileAttributes & FILE_ATTRIBUTE_SPARSE_FILE)
	{
		buffer += " :SPARSE_FILE: ";
	}
	if (file.dwFileAttributes & FILE_ATTRIBUTE_SYSTEM)
	{
		buffer += " :SYSTEM: ";
	}
	if (file.dwFileAttributes & FILE_ATTRIBUTE_TEMPORARY)
	{
		buffer += " :TEMPORARY: ";
	}
	if (file.dwFileAttributes & FILE_ATTRIBUTE_VIRTUAL)
	{
		buffer += " :VIRTUAL: ";
	}
	return buffer;
}
void outFiles(std::vector<WIN32_FIND_DATA> content_directory) {
	std::cout << "DIRECTORIES: " << std::endl;
	content_directory.erase(content_directory.begin());
	for (size_t i = 0; i < content_directory.size(); i++) {
		if (content_directory[i].dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) {

			std::wcout << "Directory: " << content_directory[i].cFileName;
			std::cout << attributeFile(content_directory[i]) << "\n\n";
			content_directory.erase(content_directory.begin() + i);
		}
	}
	std::cout << "FILES: " << std::endl;
	for (size_t i = 0; i < content_directory.size(); i++) {
		if (content_directory[i].dwFileAttributes >= 32) {
			std::wcout << "Filename: " << content_directory[i].cFileName;
			std::cout << attributeFile(content_directory[i]) << "\nSize: " << content_directory[i].nFileSizeLow;
			std::wcout << "\nExtension: " << content_directory[i].cAlternateFileName << "\n\n";
			content_directory.erase(content_directory.begin() + i);
		}
	}
}

int main()
{
	WIN32_FIND_DATA f;
	std::vector<WIN32_FIND_DATA> content_directory;
	HANDLE h = FindFirstFile(L"./*", &f);
	if (h != INVALID_HANDLE_VALUE)
	{
		do
		{
			content_directory.push_back(f);
		} while (FindNextFile(h, &f));
	}
	else
	{
		fprintf(stderr, "Error opening directory\n");
	}
	outFiles(content_directory);
	return 0;
}