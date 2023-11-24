import itertools

def cost_of_assignment(assignments, cost_matrix):
    total_cost = 0
    for student, club in enumerate(assignments):
        total_cost += cost_matrix[student][club]
    return total_cost

def branch_and_bound(N, cost_matrix):
    def branch(assignments, remaining_students, cost_bound):
        if not remaining_students:
            return cost_of_assignment(assignments, cost_matrix), assignments[:]
        min_cost = float('inf')
        best_assignment = None
        for student in remaining_students:
            for club in range(N):
                if club not in assignments:
                    new_assignments = assignments.copy()
                    new_assignments[student] = club
                    remaining = [s for s in remaining_students if s != student]
                    cost = cost_of_assignment(new_assignments, cost_matrix)
                    if cost < cost_bound:
                        new_cost_bound = cost_bound - cost_matrix[student][club]
                        cost, assignment = branch(new_assignments, remaining, new_cost_bound)
                        if cost < min_cost:
                            min_cost = cost
                            best_assignment = assignment

        return min_cost, best_assignment

    # Initialize assignments and remaining students
    initial_assignments = [-1] * N
    remaining_students = list(range(N))

    # Call the branch_and_bound function
    min_cost, best_assignment = branch(initial_assignments, remaining_students, float('inf'))

    return min_cost, best_assignment

# Example cost matrix and number of students
cost_matrix = [
    [2, 3, 1],  # Student 0's costs for clubs 0, 1, 2
    [5, 2, 4],  # Student 1's costs for clubs 0, 1, 2
    [1, 6, 2],  # Student 2's costs for clubs 0, 1, 2
]

N = len(cost_matrix)

# Call the branch_and_bound function
min_cost, best_assignment = branch_and_bound(N, cost_matrix)

# Print the result
if best_assignment is not None:
    print("Minimum Cost:", min_cost)
    print("Best Assignment:", best_assignment)
else:
    print("No valid assignment found.")