package com.cts.service;

import com.cts.dto.MemberRequest;
import com.cts.model.Member;
import com.cts.repository.MemberRepository;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import java.util.List;

@Service
public class MemberService {

    @Autowired
    private MemberRepository memberRepository;

    // Member Registration
    public Member registerMember(MemberRequest memberDTO) {
        Member member = new Member();
        member.setName(memberDTO.getName());
        member.setEmail(memberDTO.getEmail());
        member.setPhone(memberDTO.getPhone());
        member.setAddress(memberDTO.getAddress());
        member.setPassword(memberDTO.getPassword());
        member.setMembershipStatus("Active"); // default

        return memberRepository.save(member);
    }

    // Get all Members
    public List<Member> getAllMembers() {
        return memberRepository.findAll();
    }

    // Update Member details
    public Member updateMember(Long memberId, MemberRequest memberDTO) {
        Member existingMember = memberRepository.findById(memberId)
                .orElseThrow(() -> new RuntimeException("Member not found"));

        existingMember.setName(memberDTO.getName());
        existingMember.setEmail(memberDTO.getEmail());
        existingMember.setPhone(memberDTO.getPhone());
        existingMember.setAddress(memberDTO.getAddress());
        existingMember.setPassword(memberDTO.getPassword());

        return memberRepository.save(existingMember);
    }

    // Update Membership Status
    public Member updateMembershipStatus(Long memberId, String membershipStatus) {
        Member existingMember = memberRepository.findById(memberId)
                .orElseThrow(() -> new RuntimeException("Member not found"));

        existingMember.setMembershipStatus(membershipStatus);
        return memberRepository.save(existingMember);
    }

    // Delete Member
    public void deleteMember(Long memberId) {
        memberRepository.deleteById(memberId);
    }
}



