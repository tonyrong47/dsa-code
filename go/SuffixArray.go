package main

import (
	"fmt"
	"sort"
)

type suffix struct {
	index int
	rank  [2]int
}

// buildSuffixArray builds a suffix array for string s
func buildSuffixArray(s string) []int {
	n := len(s)
	suffixes := make([]suffix, n)

	// Initial ranking by first 2 chars
	for i := 0; i < n; i++ {
		rankNext := -1
		if i+1 < n {
			rankNext = int(s[i+1])
		}
		suffixes[i] = suffix{i, [2]int{int(s[i]), rankNext}}
	}

	// Sort by first 2 chars
	sort.Slice(suffixes, func(i, j int) bool {
		if suffixes[i].rank[0] == suffixes[j].rank[0] {
			return suffixes[i].rank[1] < suffixes[j].rank[1]
		}
		return suffixes[i].rank[0] < suffixes[j].rank[0]
	})

	ind := make([]int, n) // index array

	// At each step, rank by 2^k characters
	for k := 4; k < 2*n; k *= 2 {
		rank := 0
		prevRank := suffixes[0].rank
		suffixes[0].rank[0] = rank
		ind[suffixes[0].index] = 0

		for i := 1; i < n; i++ {
			if suffixes[i].rank == prevRank {
				suffixes[i].rank[0] = rank
			} else {
				prevRank = suffixes[i].rank
				rank++
				suffixes[i].rank[0] = rank
			}
			ind[suffixes[i].index] = i
		}

		for i := 0; i < n; i++ {
			nextIndex := suffixes[i].index + k/2
			if nextIndex < n {
				suffixes[i].rank[1] = suffixes[ind[nextIndex]].rank[0]
			} else {
				suffixes[i].rank[1] = -1
			}
		}

		sort.Slice(suffixes, func(i, j int) bool {
			if suffixes[i].rank[0] == suffixes[j].rank[0] {
				return suffixes[i].rank[1] < suffixes[j].rank[1]
			}
			return suffixes[i].rank[0] < suffixes[j].rank[0]
		})
	}

	// Extract suffix array
	suffixArr := make([]int, n)
	for i := 0; i < n; i++ {
		suffixArr[i] = suffixes[i].index
	}
	return suffixArr
}

func main() {
	text := "banana"
	suffixArr := buildSuffixArray(text)

	fmt.Println("Text:", text)
	fmt.Println("Suffix Array:", suffixArr)
}
