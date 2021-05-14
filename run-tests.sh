#!/usr/bin/env bash
function main()
{
	cd tests

	[[ $1 =~ ^(gdb|-g|--debug)$ ]] && { { [[ $2 ]] && echo jajaj; make "$2"; }; gdb -q ./a.out && exit; }
	[[ $1 =~ ^(out|-o|-edit-out)$ ]]  && vim output/"$2"-main && exit
	[[ $1 =~ ^(touch)$ ]]  && touch ./output/"$2"-main && exit
	[[ $1 =~ ^(main)$ ]]  && vim "$2"-main.c && exit
	[[ $1 =~ ^(run)$ ]]  && ./a.out && exit

	if [[ $# -eq 0 ]]; then
		RULES="$(find -maxdepth 1 -name '*.c' | cut -d- -f1 | cut -d/ -f2 | sort)"
	else
		RULES="$*"
	fi
	for RULE in ${RULES}; do
		echo -n "$RULE: "
		make "${RULE}" || exit 1;
		check_c_file
	done
}

check_script_file()
{
	OUTPUT_CMD="./a.out < cmd 2> *"
	OUTPUT_REF="sh < cmd"
}

check_c_file()
{
	OUTPUT_CMD="./a.out 2>&1"
	OUTPUT_REF="output/${RULE}-main"

	OUTPUT=$(diff <($OUTPUT_CMD) "$OUTPUT_REF" \
		--unchanged-line-format="" --old-line-format="" --new-line-format="%dn- %L")
	OUTPUT=$(diff <($OUTPUT_CMD) "$OUTPUT_REF")

	if [[ -z $OUTPUT ]]; then
		echo -ne "\033[32mOK\033[00m"
	else
		echo;
		echo "$OUTPUT"
		echo -ne "\033[31mKO\033[00m"
	fi

	## Search in the main file for the entry point documentation
	#REG_F_INFO="s, \* main - \(.*\)$, \1,p"
	#[[ $? -eq 0 ]] && sed -n "$REG_F_INFO" "${RULE}-main.c"

	## Search in the bin file for the entry point documentation
	REG_F_INFO="s/.* \* main - \(.*$\)/ \1/p"
	gdb ./a.out -ex "list 1, 9999" -ex "quit" |\
	sed -n "$REG_F_INFO"
}

doc_reference()
{
	sed -n "/Output:/,/*/p" "$RULE"-main.c \|
		cut -c 4- \|
		tail -n +2
	}

main "$@"
