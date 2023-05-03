input_file_name=""
for file in $(ls | grep part_); do
    input_file_name=${file}
    echo processing ${input_file_name}
    cat ./${input_file_name} | sed -E 's/NumberInt\(([0-9]+)\)/\1/g' > ./${input_file_name}.json 
done


