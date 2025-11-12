import java.io.*;
import java.util.*;

public class pass1 {
    static Map<String, String> opcodeTable = new HashMap<>();
    static Map<String, String> regTable = new HashMap<>();
    static Map<String, Integer> symbolTable = new LinkedHashMap<>();
    static Map<String, Integer> literalTable = new LinkedHashMap<>();
    static List<String[]> intermediateCode = new ArrayList<>();
    static int locCounter = 0;
    static int literalIndex = 1;

    public static void main(String[] args) throws IOException {
        initializeTables();
        passOne("Input.txt");
        writeIC("IC.txt");
        writeTable("SYMTAB.txt", symbolTable);
        writeTable("LITTAB.txt", literalTable);
    }

    static void initializeTables() {
        opcodeTable.put("START", "AD 01");
        opcodeTable.put("END", "AD 02");
        opcodeTable.put("LTORG", "AD 05");
        opcodeTable.put("STOP", "IS 00");
        opcodeTable.put("ADD", "IS 01");
        opcodeTable.put("SUB", "IS 02");
        opcodeTable.put("MOVER", "IS 04");
        opcodeTable.put("MOVEM", "IS 05");
        opcodeTable.put("DS", "DL 02");

        regTable.put("AREG", "1");
        regTable.put("BREG", "2");
        regTable.put("CREG", "3");
        regTable.put("DREG", "4");
    }

    static void passOne(String filename) throws IOException {
        BufferedReader br = new BufferedReader(new FileReader(filename));
        String line;
        int literalCounter = 1;

        while ((line = br.readLine()) != null) {
            line = line.trim();
            if (line.isEmpty()) continue;

            String[] parts = line.split("[\\s,]+");
            String label = null, opcode, op1 = null, op2 = null;

            if (opcodeTable.containsKey(parts[0])) {
                opcode = parts[0];
                if (parts.length > 1) op1 = parts[1];
                if (parts.length > 2) op2 = parts[2];
            } else {
                label = parts[0];
                opcode = parts[1];
                if (parts.length > 2) op1 = parts[2];
                if (parts.length > 3) op2 = parts[3];
                symbolTable.put(label, locCounter);
            }

            if (opcode.equals("START")) {
                locCounter = Integer.parseInt(op1);
                intermediateCode.add(new String[]{"AD", "01", "C", op1});
                continue;
            }

            if (opcode.equals("END") || opcode.equals("LTORG")) {
                for (String lit : literalTable.keySet()) {
                    if (literalTable.get(lit) == -1) {
                        literalTable.put(lit, locCounter++);
                        intermediateCode.add(new String[]{"AD", "02", "C", lit.replaceAll("[='']", "")});
                    }
            }
                if (opcode.equals("END")) {
                    intermediateCode.add(new String[]{"AD", "02"});
                } else {
                    intermediateCode.add(new String[]{"AD", "05"});
                }
                continue;
            }

            String[] code = opcodeTable.get(opcode).split(" ");
            List<String> ic = new ArrayList<>();
            ic.add(code[0]);
            ic.add(code[1]);

            if (opcode.equals("DS")) {
                ic.add("C");
                ic.add(op1);
                locCounter += Integer.parseInt(op1);
            } else {
                if (op1 != null) {
                    if (regTable.containsKey(op1)) {
                        ic.add(regTable.get(op1));
                    } else if (op1.startsWith("='")) {
                        literalTable.putIfAbsent(op1, -1);
                        ic.add("L");
                        ic.add(String.valueOf(getLiteralIndex(op1)));
                    } else {
                        symbolTable.putIfAbsent(op1, -1);
                        ic.add("S");
                        ic.add(String.valueOf(getSymbolIndex(op1)));
                    }
                }
                if (op2 != null) {
                    if (op2.startsWith("='")) {
                        literalTable.putIfAbsent(op2, -1);
                        ic.add("L");
                        ic.add(String.valueOf(getLiteralIndex(op2)));
                    } else {
                        symbolTable.putIfAbsent(op2, -1);
                        ic.add("S");
                        ic.add(String.valueOf(getSymbolIndex(op2)));
                    }
                }
                locCounter++;
            }

            intermediateCode.add(ic.toArray(new String[0]));
        }
        br.close();
    }

    static int getSymbolIndex(String symbol) {
        int index = 1;
        for (String sym : symbolTable.keySet()) {
            if (sym.equals(symbol)) return index;
            index++;
        }
        return index;
    }

    static int getLiteralIndex(String lit) {
        int index = 1;
        for (String l : literalTable.keySet()) {
            if (l.equals(lit)) return index;
            index++;
        }
        return index;
    }

    static void writeIC(String filename) throws IOException {
        BufferedWriter bw = new BufferedWriter(new FileWriter(filename));
        for (String[] line : intermediateCode) {
            for (String word : line) {
                bw.write(word + "\t");
            }
            bw.newLine();
        }
        bw.close();
    }

   static void writeTable(String file, Map<String, Integer> table) throws IOException {
    BufferedWriter bw = new BufferedWriter(new FileWriter(file));
    for (String key : table.keySet()) {
        bw.write(key + "\t" + table.get(key) + "\n");
    }
    bw.close();
}
}
//START 200
//MOVER AREG, ='5'
//ADD BREG, X
//MOVEM AREG, Y
//X DS 1
//Y DS 1
//END



