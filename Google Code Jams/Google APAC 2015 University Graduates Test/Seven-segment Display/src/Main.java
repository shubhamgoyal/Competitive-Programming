import java.io.IOException;
import java.util.Arrays;
import java.util.Collections;
import java.util.Scanner;
import java.util.Vector;


public class Main {
	static int[][] correctOrder = {{1, 1, 1, 1, 0, 1, 1}, {1, 1, 1, 1, 1, 1, 1}, {1, 1, 1, 0, 0, 0, 0}, {1, 0, 1, 1, 1, 1, 1}, {1, 0, 1, 1, 0, 1, 1}, {0, 1, 1, 0, 0, 1, 1}, {1, 1, 1, 1, 0, 0, 1}, {1, 1, 0, 1, 1, 0, 1}, {0, 1, 1, 0, 0, 0, 0}, {1, 1, 1, 1, 1, 1, 0}};
	public static void main(String args[]) throws IOException {
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();
		for (int i = 0; i < T; i++) {
			Vector<Integer> positionsWhichCannotBeBroken = new Vector<Integer>();
			int N = sc.nextInt();
			int states[][] = new int[N][7];
			for (int j = 0; j < N; j++) {
				int state = sc.nextInt();
				states[j][6] = state % 10;
				state = state / 10;
				states[j][5] = state % 10;
				state = state / 10;
				states[j][4] = state % 10;
				state = state / 10;
				states[j][3] = state % 10;
				state = state / 10;
				states[j][2] = state % 10;
				state = state / 10;
				states[j][1] = state % 10;
				state = state / 10;
				states[j][0] = state % 10;
				state = state / 10;
			}
			for (int j = 0; j < N; j++) {
				for (int k = 0; k < 7; k++) {
					if (states[j][k] == 1) {
						if (!positionsWhichCannotBeBroken.contains(k)) {
							positionsWhichCannotBeBroken.add(k);
						}
					}
				}
			}
			Vector<Vector<Vector<Integer>>> possibleSolutions = new Vector<Vector<Vector<Integer>>>();
			boolean blackFlag = true;
			for (int num = 0; num < (2*2*2*2*2*2*2); num ++) {
				Vector<Integer> allowedPositions = new Vector<Integer>();
				int divisor = 2;
				int numCopy = num;
				for (int j = 6; j >= 0; j--) {
					int remainder = numCopy % divisor;
					numCopy = numCopy / divisor;
					if (remainder > 0) {
						allowedPositions.add(j);
					}
				}
				Collections.sort(allowedPositions);
//				System.out.println(num);
//				System.out.println(allowedPositions.toString());
				int z = 0;
				for (z = 0; z < 7; z++) {
					if (!allowedPositions.contains(z) && positionsWhichCannotBeBroken.contains(z)) {
						break;
					}
				}
				if (z != 7) {
					continue;
				}
//				System.out.println(num);
//				System.out.println("allowedPositions = " + allowedPositions);
//				System.out.println(allowedPositions.toString());
				Vector<Vector<Integer>> possibleSolution = canSequenceExistWithAllowedPositions(states, allowedPositions);
//				
//				System.out.println("possibleSolutions = " + possibleSolutions.toString());
//				if (!possibleSolutions.contains(possibleSolution) && possibleSolution != -1) {
				if (possibleSolution.size() == 3) {
					blackFlag = false;
					break;
				}
//				if (possibleSolution.size() != 1) {
//					possibleSolutions = doSomething(possibleSolutions, possibleSolution);
//				}
				if (possibleSolution.size() != 1) {
					possibleSolutions.add(possibleSolution);
				}
//				System.out.println("possibleSolution = " + possibleSolution);
//				System.out.println(possibleSolutions);
			}
			if (!blackFlag) {
				System.out.println("Case #" + (i + 1) + ": " + "ERROR!");
			}
			else if (possibleSolutions.size() == 1) {
				int answer = possibleSolutions.get(0).get(0).get(0);
				String answerString = Integer.toString(answer);
				while (answerString.length() != 7) {
					answerString = "0" + answerString;
				}
				System.out.println("Case #" + (i + 1) + ": " + answerString);
			} else {
				System.out.println("Case #" + (i + 1) + ": " + "ERROR!");
			}
		}
	}

//	private static Vector<Vector<Vector<Integer>>> doSomething(
//			Vector<Vector<Vector<Integer>>> possibleSolutions,
//			Vector<Vector<Integer>> possibleSolution) {
//		int i = 0;
//		for (i = 0; i < possibleSolutions.size(); i++) {
//			boolean flag = true;
//			Vector<Integer> vector1 = possibleSolutions.get(i).get(1);
//			Vector<Integer> vector2 = possibleSolution.get(1);
//			for (int j = 0; j < vector1.size(); j++) {
//				if (!vector2.contains(vector1.get(j))) {
//					flag = false;
//				}
//			}
//			if (flag == true) {
//				possibleSolutions.remove(i);
//				possibleSolutions.add(possibleSolution);
//				break;
//			}
//		}
//		if (i == possibleSolutions.size()) {
//			possibleSolutions.add(possibleSolution);
//		}
//		return possibleSolutions;
//	}

	private static Vector<Vector<Integer>> canSequenceExistWithAllowedPositions(int[][] states,
			Vector<Integer> allowedPositions) {
		
		Vector<Integer> possibleNewStates = new Vector<Integer>();
		int newStates[][] = new int[states.length][allowedPositions.size()];
		for (int i = 0; i < states.length; i++) {
			for (int j = 0; j < allowedPositions.size(); j++) {
				newStates[i][j] = states[i][allowedPositions.get(j)];
			}
		}
		int newCorrectOrder[][] = new int[10][allowedPositions.size()];
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < allowedPositions.size(); j++) {
				newCorrectOrder[i][j] = correctOrder[i][allowedPositions.get(j)];
			}
		}
		for (int i = 0; i < 10; i++) {
			boolean doArraysMatch = true;
			int position = i;
			for (int j = 0; j < newStates.length; j++) {
				if (!Arrays.equals(newCorrectOrder[position], newStates[j])) {
					doArraysMatch = false;
					break;
				}
				position = (position + 1) % 10;
			}
			if (doArraysMatch) {
				int num = 0;
				for (int j = 0; j < 7; j++) {
					if (allowedPositions.contains(j)) {
						num = num * 10 + correctOrder[position][j];
					}
					else {
						num = num * 10;
					}
				}
//				if (!possibleNewStates.contains(num)) {
					possibleNewStates.add(num);
//				}
			}
		}
//		System.out.println(possibleNewStates.toString());
		Vector<Vector<Integer>> answer = new Vector<Vector<Integer>>();
//		System.out.println("possibleNewStates = " + possibleNewStates);
		if (possibleNewStates.size() == 1) {
			answer.add(new Vector<Integer>());
			answer.get(0).add(possibleNewStates.get(0));
			answer.add(allowedPositions);
			return answer;
		} else if (possibleNewStates.size() > 1) {
			answer.add(new Vector<Integer>());
			answer.add(new Vector<Integer>());
			answer.add(new Vector<Integer>());
			return answer;
		}
		else {
			answer.add(new Vector<Integer>());
			return answer;
		}
	}
}
