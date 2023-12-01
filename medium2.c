[{"insert":"Medium 2 \nGiven an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times.\n \nExample 1:\nInput: nums = [3,2,3]\nOutput: [3]\nExample 2:\nInput: nums = [1]\nOutput: [1]\nExample 3:\nInput: nums = [1,2]\nOutput: [1,2]\n\nCODE\n\n#include <stdio.h>\n#include <stdlib.h>\n\nint* majorityElement(int* nums, int numsSize, int* returnSize) {\n    int candidate1 = 0, candidate2 = 0;\n    int count1 = 0, count2 = 0;\n\n    for (int i = 0; i < numsSize; i++) {\n        if (nums[i] == candidate1) {\n            count1++;\n        } else if (nums[i] == candidate2) {\n            count2++;\n        } else if (count1 == 0) {\n            candidate1 = nums[i];\n            count1 = 1;\n        } else if (count2 == 0) {\n            candidate2 = nums[i];\n            count2 = 1;\n        } else {\n            count1--;\n            count2--;\n        }\n    }\n\n    count1 = 0, count2 = 0;\n    for (int i = 0; i < numsSize; i++) {\n        if (nums[i] == candidate1) {\n            count1++;\n        } else if (nums[i] == candidate2) {\n            count2++;\n        }\n    }\n\n    *returnSize = 0;\n    int* result = (int*)malloc(sizeof(int) * 2);\n\n    if (count1 > numsSize / 3) {\n        result[(*returnSize)++] = candidate1;\n    }\n    if (count2 > numsSize / 3 && candidate2 != candidate1) {\n        result[(*returnSize)++] = candidate2;\n    }\n\n    return result;\n}\n\nint main() {\n    int nums[] = {3, 2, 3};\n    int size = sizeof(nums) / sizeof(nums[0]);\n\n    int returnSize;\n    int* result = majorityElement(nums, size, &returnSize);\n\n    printf(\"Elements appearing more than ⌊n/3⌋ times: \");\n    for (int i = 0; i < returnSize; i++) {\n        printf(\"%d \", result[i]);\n    }\n    free(result);\n\n    return 0;\n}\nOUTPUT\nElements appearing more than ⌊n/3⌋ times: 3\n\n"}]