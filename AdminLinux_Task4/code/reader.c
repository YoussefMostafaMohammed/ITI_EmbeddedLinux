#include <stdio.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>

#define SHARED_MEM_NAME "/SharedBuf"
#define SHARED_MEM_SIZE 4096U
#define SHARED_MEM_PRIVILEGE 0666U

int main(void)
{
    int FileDesc = -1;
    int Err = 1;
    void *MappedMem = NULL;

    // Open the shared memory object
    FileDesc = shm_open(SHARED_MEM_NAME, O_RDONLY, SHARED_MEM_PRIVILEGE);
    if (-1 == FileDesc)
    {
        perror("Can NOT open shared memory");
        return 1;
    }

    // Map shared memory
    MappedMem = mmap(NULL, SHARED_MEM_SIZE, PROT_READ, MAP_SHARED, FileDesc, 0U);
    if (MAP_FAILED == MappedMem)
    {
        perror("Can NOT map shared memory");
        return 1;
    }

    // Read and print message from shared memory
    printf("Reader read: %s", (char *)MappedMem);

    // Unmap shared memory
    Err = munmap(MappedMem, SHARED_MEM_SIZE);
    if (-1 == Err)
    {
        perror("Can NOT unmap shared memory");
        return 1;
    }

    // Close shared memory object
    Err = close(FileDesc);
    if (-1 == Err)
    {
        perror("Can NOT close file descriptor");
        return 1;
    }

    return 0;
}

