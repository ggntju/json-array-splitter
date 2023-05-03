input_file="./dblpv13.json"
output_file="./dblpv13_post.json"
perl -pe 's/\r\n//g' ${input_file} > ${output_file}
